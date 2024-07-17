package cn.tedu.DogWalkingAppointment.service.impl;

import cn.tedu.DogWalkingAppointment.entity.Appointment;
import cn.tedu.DogWalkingAppointment.entity.Customer;
import cn.tedu.DogWalkingAppointment.entity.User;
import cn.tedu.DogWalkingAppointment.mapper.AppointmentMapper;
import cn.tedu.DogWalkingAppointment.mapper.CustomerMapper;
import cn.tedu.DogWalkingAppointment.mapper.UserMapper;
import cn.tedu.DogWalkingAppointment.service.IAppointmentService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.util.Date;
import java.util.List;

@Service
public class AppointmentServiceImpl implements IAppointmentService {
    @Autowired
    private AppointmentMapper appointmentMapper;
    @Autowired
    private CustomerMapper customerMapper;
    public void addAppointment(Integer dogId, Integer userId, Date sTime, Date eTime){
        Appointment a=new Appointment();
        a.setDogId(dogId);

        Customer c=customerMapper.findByUserId(userId);
        a.setCustomerId(c.getCustomerId());
        a.setStartTime(sTime);
        a.setEndTime(eTime);
        Date date=new Date();
        a.setModifiedTime(date);
        a.setCreatedTime(date);
        a.setCreatedUser(c.getCustomerName());
        a.setModifiedUser(c.getCustomerName());

        appointmentMapper.insert(a);
    }

    public List<Appointment> findAppointmentList(Integer cid){
        List<Appointment> list=appointmentMapper.findByCustomerId(cid);

        return list;
    }

    public List<Appointment> findAppointmentListByDogId(Integer did){
        List<Appointment> list=appointmentMapper.findByCustomerId(did);
        return list;
    }

    public Appointment findAppointmentByAid(Integer aid){
        Appointment a=appointmentMapper.findByAid(aid);
        return a;
    }
}
