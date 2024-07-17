package cn.tedu.DogWalkingAppointment;

import cn.tedu.DogWalkingAppointment.entity.CustomerReview;
import cn.tedu.DogWalkingAppointment.entity.DogReview;
import cn.tedu.DogWalkingAppointment.mapper.CustomerReviewMapper;
import org.junit.jupiter.api.Test;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.context.SpringBootTest;

import java.util.Date;

@SpringBootTest
public class CustomerReviewMapperTests {
    @Autowired
    private CustomerReviewMapper customerReviewMapper;
    @Test
    void insertTest(){
//        CustomerReview c=new CustomerReview();
//        c.setCreviewId(1);;
//        c.setCustomerId(null);
//        c.setRating(0.5);
//        c.setComment("神经病，为什么打我的狗");
//        c.setCreatedUser("1");
//
//
//        customerReviewMapper.addNewComment(c);
    }
    @Test
    public void test01(){
        System.out.println(customerReviewMapper.showReviews(1));
    }
}
