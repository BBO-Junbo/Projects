package cn.tedu.DogWalkingAppointment;

import cn.tedu.DogWalkingAppointment.entity.CustomerReview;
import cn.tedu.DogWalkingAppointment.service.impl.CustomerReviewServiceImpl;
import org.junit.jupiter.api.Test;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.context.SpringBootTest;

@SpringBootTest
public class CustomerReviewServiceTests {
    @Autowired
    CustomerReviewServiceImpl customerReviewService;

    @Test
    public void commentTest(){
        CustomerReview customerReview=new CustomerReview();
        customerReview.setComment("没有下次了");
        customerReview.setCreatedUser("kmasdkhu");
        customerReviewService.comment(customerReview);
    }
    @Test
    public void show(){
        System.out.println(customerReviewService.getAllReviews(1));
    }
}
