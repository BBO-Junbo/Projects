package cn.tedu.DogWalkingAppointment.mapper;

import cn.tedu.DogWalkingAppointment.entity.Dog;
import cn.tedu.DogWalkingAppointment.entity.DogAvailability;
import cn.tedu.DogWalkingAppointment.entity.DogReview;

import java.util.List;

public interface DogAvailabilityMapper {
    Integer insert(DogAvailability dogAvailability);
    List<DogAvailability> findByDogid(Integer dogId);
    List<DogAvailability> findAllDogAvailability();
    DogAvailability findByAvailabilityId(Integer availabilityId);
    Integer deleteByAvailabilityId(Integer availabilityId);
    Integer changeIsReservedByAvailabilityId(Integer availabilityId);//实现预约

}
