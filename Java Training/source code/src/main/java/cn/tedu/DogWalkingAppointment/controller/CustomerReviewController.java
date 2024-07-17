package cn.tedu.DogWalkingAppointment.controller;

import cn.tedu.DogWalkingAppointment.entity.Appointment;
import cn.tedu.DogWalkingAppointment.entity.CustomerReview;
import cn.tedu.DogWalkingAppointment.entity.Dog;
import cn.tedu.DogWalkingAppointment.entity.DogReview;
import cn.tedu.DogWalkingAppointment.service.IAppointmentService;
import cn.tedu.DogWalkingAppointment.service.ICustomerReviewService;
import cn.tedu.DogWalkingAppointment.util.JsonResult;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.Mapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.RestController;

import javax.servlet.http.HttpSession;
import java.util.Date;
import java.util.List;

@RestController
@RequestMapping("comment0")
public class CustomerReviewController extends BaseController{
    @Autowired
    private ICustomerReviewService customerReviewService;
    @Autowired
    private IAppointmentService appointmentService;

    //http://localhost:8000/comment0/submit0?appointmentId=9&comment=22132139999999&rating=4
    @RequestMapping("submit0")//提交评论
    public JsonResult<Void> submitComment(@RequestParam Integer appointmentId, @RequestParam String comment,@RequestParam Double rating, HttpSession session) {
        Integer userId=getUidFromSession(session);
        Appointment appointment=appointmentService.findAppointmentByAid(appointmentId);
        Integer customerId=appointment.getCustomerId();

        CustomerReview customerReview=new CustomerReview();
        customerReview.setCustomerId(customerId);
        customerReview.setComment(comment);
        customerReview.setRating(rating);
        customerReview.setAppointmentId(appointmentId);
        customerReview.setCreatedUser(getUsernameFromSession(session));
        customerReview.setCreatedTime(new Date());
        customerReview.setUserId(userId);


        customerReviewService.comment(customerReview);
        return new JsonResult<Void>(200, null, null);
    }
    @RequestMapping("/reviews")
    public JsonResult<List<CustomerReview>> getAllReviews(Integer customerId) {
        List<CustomerReview> data = customerReviewService.getAllReviews(customerId);
        return new JsonResult<>(200,null,data);
    }
}
