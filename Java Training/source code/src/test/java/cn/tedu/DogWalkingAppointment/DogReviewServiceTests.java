package cn.tedu.DogWalkingAppointment;

import cn.tedu.DogWalkingAppointment.entity.DogReview;
import cn.tedu.DogWalkingAppointment.service.impl.DogreviewServiceImpl;
import org.junit.jupiter.api.Test;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.context.SpringBootTest;

import java.util.Date;

@SpringBootTest
public class DogReviewServiceTests {
    @Autowired
    private DogreviewServiceImpl dogreviewService;

    @Test
    public void commentTest(){

//        dogreviewService.comment(2,2,2,1.111,"不咋地");
    }

}
