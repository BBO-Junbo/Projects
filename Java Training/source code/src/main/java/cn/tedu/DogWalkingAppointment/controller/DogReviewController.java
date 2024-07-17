package cn.tedu.DogWalkingAppointment.controller;

import cn.tedu.DogWalkingAppointment.entity.*;
import cn.tedu.DogWalkingAppointment.service.ICustomerReviewService;
import cn.tedu.DogWalkingAppointment.service.IDogreviewService;
import cn.tedu.DogWalkingAppointment.service.impl.AppointmentServiceImpl;
import cn.tedu.DogWalkingAppointment.util.JsonResult;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.RestController;

import javax.servlet.http.HttpSession;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.List;

@RestController
@RequestMapping("comment")
public class DogReviewController extends BaseController{
    @Autowired
    private IDogreviewService dogreviewService;
    @Autowired
    private AppointmentServiceImpl appointmentService;

    //http://localhost:8000/comment/submit?appointmentId=3&comment=2213213&rating=5
    @RequestMapping("submit")//提交评论
    public JsonResult<Void> submitComment(@RequestParam Integer appointmentId, @RequestParam String comment, @RequestParam Double rating, HttpSession session) {
        Integer userId=getUidFromSession(session);
        Appointment appointment=appointmentService.findAppointmentByAid(appointmentId);
        Integer dogId=appointment.getDogId();

        DogReview dogReview=new DogReview();
        dogReview.setDogId(dogId);
        dogReview.setComment(comment);
        dogReview.setRating(rating);
        dogReview.setAppointmentId(appointmentId);
        dogReview.setUserId(userId);
        dogReview.setCreatedUser(getUsernameFromSession(session));
        dogReview.setCreatedTime(new Date());

        dogreviewService.comment(dogReview);
        return new JsonResult<Void>(200, null, null);
    }
    @RequestMapping("/comments")
    public JsonResult<List<DogReview>> getAllReviews(Integer dogId) {
        List<DogReview> data = dogreviewService.getAllReviews(dogId);
        System.out.println("666");
        return new JsonResult<>(200,null,data);
    }
}
