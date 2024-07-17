package cn.tedu.DogWalkingAppointment;

import cn.tedu.DogWalkingAppointment.entity.DogAvailability;
import cn.tedu.DogWalkingAppointment.mapper.DogAvailabilityMapper;
import org.junit.jupiter.api.Test;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.context.SpringBootTest;

import java.util.Date;

@SpringBootTest
public class DogavailabilityMapperTest {
    @Autowired
    DogAvailabilityMapper m;
    @Test
    public void Test01(){
        DogAvailability d=new DogAvailability();
        d.setAvailabilityId(55);
        d.setDogId(1);
        d.setIsReserved(true);
        d.setStartTime(new Date());
        d.setEndTime(new Date());
        m.insert(d);
}
@Test
    public void Test02(){
        System.out.println(m.findByDogid(1));
    }
    @Test
    public void Test03(){
        m.changeIsReservedByAvailabilityId(1);
        m.changeIsReservedByAvailabilityId(2);
        m.changeIsReservedByAvailabilityId(3);
        m.changeIsReservedByAvailabilityId(4);
        m.changeIsReservedByAvailabilityId(5);
        m.changeIsReservedByAvailabilityId(6);
        m.changeIsReservedByAvailabilityId(7);
        m.changeIsReservedByAvailabilityId(8);
    }
}
