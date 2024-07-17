package cn.tedu.DogWalkingAppointment;
import cn.tedu.DogWalkingAppointment.ex.ServiceException;
import cn.tedu.DogWalkingAppointment.entity.DogAvailability;
import cn.tedu.DogWalkingAppointment.service.IDogAvailabilityService;
import org.junit.jupiter.api.Test;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.context.SpringBootTest;

import javax.sql.rowset.serial.SerialException;
import java.util.Date;
@SpringBootTest
public class DogAvailabilityServiceTests {
    @Autowired
    private IDogAvailabilityService s;
    @Test
    public void test01(){

            Integer dogId=1;
            String username="tom";
            DogAvailability da=new DogAvailability();
            da.setDogId(dogId);
            da.setStartTime(new Date());
            da.setEndTime(new Date());
            da.setAvailabilityId(3);
            da.setIsReserved(true);
            da.setCreatedTime(new Date());
            da.setCreatedUser(username);
            da.setModifiedTime(new Date());
            da.setModifiedUser(username);


            s.addNewAvailability(dogId,username,da);

    }
    @Test
    public void test02(){
        s.deleteAvalibilityId(6);
    }
    @Test
    public void test03(){
        System.out.println(s.getByDog_id(1));;
    }
}
