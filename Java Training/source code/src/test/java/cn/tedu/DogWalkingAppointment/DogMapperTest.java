package cn.tedu.DogWalkingAppointment;

import cn.tedu.DogWalkingAppointment.mapper.DogMapper;
import cn.tedu.DogWalkingAppointment.mapper.DogReviewMapper;
import org.junit.jupiter.api.Test;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.context.SpringBootTest;

@SpringBootTest
public class DogMapperTest {
    @Autowired
    private DogMapper m;
    @Test
    public void test01(){

        System.out.println(m.findByDogId(4));
    }
}
