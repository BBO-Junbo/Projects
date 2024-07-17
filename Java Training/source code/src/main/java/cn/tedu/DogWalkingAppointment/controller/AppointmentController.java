package cn.tedu.DogWalkingAppointment.controller;


import cn.tedu.DogWalkingAppointment.entity.*;
import cn.tedu.DogWalkingAppointment.mapper.CustomerMapper;
import cn.tedu.DogWalkingAppointment.service.IAppointmentService;
import cn.tedu.DogWalkingAppointment.service.ICustomerService;
import cn.tedu.DogWalkingAppointment.service.IDogService;
import cn.tedu.DogWalkingAppointment.service.impl.AppointmentServiceImpl;
import cn.tedu.DogWalkingAppointment.util.JsonResult;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.RestController;

import javax.servlet.http.HttpSession;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.Date;
import java.util.List;

@RestController
@RequestMapping("/appointment")
public class AppointmentController extends BaseController{
    @Autowired
    IAppointmentService appointmentService;
    @Autowired
    ICustomerService customerService;
    @Autowired
    CustomerMapper customerMapper;

    @Autowired
    private IDogService dogService;
    @RequestMapping("add_new_appointment")
    public JsonResult<Void> addNewappointment(Integer dogId, String startTime, String endTime, HttpSession session) {
        System.out.println("*****************************************************");
        Integer userid=getUidFromSession(session);

        SimpleDateFormat dateFormat = new SimpleDateFormat("yyyy-MM-dd'T'HH:mm");
        try {
            Date startDate = dateFormat.parse(startTime);
            Date endDate = dateFormat.parse(endTime);
            appointmentService.addAppointment(dogId,userid,startDate,endDate);
        } catch (ParseException e) {
            // 处理日期解析错误
            e.printStackTrace();
        }

        return new JsonResult<Void>(200, null, null);
    }

    //http://localhost:8000/appointment/appointment_list
    @RequestMapping("appointment_list")
    public JsonResult<List<Appoint1>> AppointmentList(HttpSession session){
        Integer uid=getUidFromSession(session);
        Customer c=customerMapper.findByUserId(uid);
        Integer cid=c.getCustomerId();
        List<Appointment>data=appointmentService.findAppointmentList(cid);
        List<Appoint1>data0=new ArrayList<Appoint1>();

        for(Appointment a:data){
            Dog dog=dogService.getByDogId(a.getDogId());
            //拼接dog和appointment的信息，形成一个新的appoint类型

            Appoint1 cur=new Appoint1();
            cur.setDogName(dog.getDogName());
            cur.setDogBreed(dog.getDogBreed());
            cur.setDogAge(dog.getDogAge());
            cur.setStartTime(a.getStartTime());
            cur.setEndTime(a.getEndTime());
            cur.setMasterName(dog.getMasterName());
            cur.setImageUrl(dog.getImageUrl());
            cur.setAppointmentId(a.getAppointmentId());
            //设置appoint类型，用来显示新表格

            data0.add(cur);
        }


        return new JsonResult<List<Appoint1>>(200,null,data0);
    }
    //http://localhost:8000/appointment/now_appointment
    @GetMapping ("now_appointment")
    public JsonResult<Appoint1> Appointment(@RequestParam("appointmentId") Integer appointmentId){

        Appointment appointment=appointmentService.findAppointmentByAid(appointmentId);
        Integer dogId=appointment.getDogId();
        Dog dog=dogService.getByDogId(dogId);


        Appoint1 cur=new Appoint1();
        cur.setDogName(dog.getDogName());
        cur.setDogBreed(dog.getDogBreed());
        cur.setDogAge(dog.getDogAge());
        cur.setStartTime(appointment.getStartTime());
        cur.setEndTime(appointment.getEndTime());
        cur.setMasterName(dog.getMasterName());
        cur.setImageUrl(dog.getImageUrl());
        cur.setAppointmentId(appointment.getAppointmentId());
            //设置appoint类型，用来显示新表格

        return new JsonResult<Appoint1>(200,null,cur);
    }


    //http://localhost:8000/appointment/appointment_list0
    @RequestMapping("appointment_list0")
    public JsonResult<List<Appoint2>> AppointmentList2(HttpSession session){
        Integer uid=getUidFromSession(session);
        List<Dog> dogList=dogService.getByUid(uid);
        List<Appoint2>data0=new ArrayList<Appoint2>();

        for(Dog d:dogList){
            List<Appointment> appointmentList=appointmentService.findAppointmentListByDogId(d.getDogId());

            for(Appointment appointment:appointmentList){
                Appoint2 appoint2=new Appoint2();
                Customer c=new Customer();
                c=customerService.getByCustomerId(appointment.getCustomerId());
                appoint2.setCustomerName(c.getCustomerName());
                appoint2.setDogName(d.getDogName());
                appoint2.setDogBreed(d.getDogBreed());
                appoint2.setDogAge(d.getDogAge());
                appoint2.setDogGender(d.getDogGender());
                appoint2.setStartTime(appointment.getStartTime());
                appoint2.setEndTime(appointment.getEndTime());
                appoint2.setImageUrl(d.getImageUrl());
                appoint2.setAppointmentId(appointment.getAppointmentId());
                data0.add(appoint2);
            }
        }
        return new JsonResult<List<Appoint2>>(200,null,data0);
    }
}
