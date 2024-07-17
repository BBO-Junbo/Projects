package cn.tedu.DogWalkingAppointment.controller;

import cn.tedu.DogWalkingAppointment.entity.Dog;
import cn.tedu.DogWalkingAppointment.entity.DogAvailability;
import cn.tedu.DogWalkingAppointment.service.IDogAvailabilityService;
import cn.tedu.DogWalkingAppointment.util.JsonResult;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.*;

import javax.servlet.http.HttpSession;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.List;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Date;
@RestController
@RequestMapping("availability")
public class AvailabilityController extends BaseController{
    @Autowired
    IDogAvailabilityService dogAvailabilityService;
    @RequestMapping("add_new_availability")
    public JsonResult<Void> addNewAvailability(Integer dogId, String starttime, String endtime, HttpSession session) {
        String username = getUsernameFromSession(session);
        DogAvailability dogAvailability = new DogAvailability();

        SimpleDateFormat dateFormat = new SimpleDateFormat("yyyy-MM-dd'T'HH:mm");
        try {
            Date startDate = dateFormat.parse(starttime);
            Date endDate = dateFormat.parse(endtime);

            dogAvailability.setStartTime(startDate);
            dogAvailability.setEndTime(endDate);
        } catch (ParseException e) {
            // 处理日期解析错误
            e.printStackTrace();
        }
        dogAvailability.setIsReserved(Boolean.FALSE);

        dogAvailabilityService.addNewAvailability(dogId, username, dogAvailability);
        return new JsonResult<Void>(200, null, null);
    }


    @GetMapping({"","/"})
    public JsonResult<List<DogAvailability>> getDogAvailabilityByDogId(@RequestParam("dogId") Integer dogId) {
        List<DogAvailability> data = dogAvailabilityService.getByDog_id(dogId);
        return new JsonResult<>(200, null, data);
    }
    @RequestMapping("/guest_availability")
    public JsonResult<List<DogAvailability>> getDogAvailability() {
        List<DogAvailability> data = dogAvailabilityService.getAllAvailability();
        return new JsonResult<List<DogAvailability>>(200, null, data);
    }

    @RequestMapping("{availabilityId}/delete")
    public JsonResult<Void> deleteByAvailabilityId(@PathVariable("availabilityId") Integer availabilityId) {
        dogAvailabilityService.deleteAvalibilityId(availabilityId);
        return new JsonResult<Void>(200,null,null);
    }

    @RequestMapping("reserve")
    public JsonResult<Void> changeAvailability(@RequestParam Integer availabilityId) {
        // 根据availabilityId进行逻辑判断和处理
        boolean success = reserveAvailability(availabilityId);
        if (success) {
            return new JsonResult<>(200, "预约成功", null);
        } else {
            return new JsonResult<>(400, "预约失败", null);
        }
    }


    // 根据availabilityId进行逻辑判断和处理的方法
    private boolean reserveAvailability(Integer availabilityId) {
        dogAvailabilityService.changeIsReserved(availabilityId);
        return true; // 预约成功
    }
}
