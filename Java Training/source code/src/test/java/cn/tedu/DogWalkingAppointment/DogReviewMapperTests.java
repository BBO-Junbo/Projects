package cn.tedu.DogWalkingAppointment;

import cn.tedu.DogWalkingAppointment.entity.DogReview;
import cn.tedu.DogWalkingAppointment.mapper.DogReviewMapper;
import org.junit.jupiter.api.Test;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.context.SpringBootTest;

import java.util.Date;

@SpringBootTest
public class DogReviewMapperTests {
    @Autowired
    DogReviewMapper dogReviewMapper;

    @Test
    void insertTest(){
        DogReview dogReview=new DogReview();
        dogReview.setDogId(2);
        dogReview.setAppointmentId(2);
        dogReview.setRating(0.5);
        dogReview.setComment("傻逼东西，敢咬我");
        Date now=new Date();
        dogReview.setCreatedUser("1");
        dogReview.setCreatedTime(now);


        dogReviewMapper.addNewComment(dogReview);
    }
}
