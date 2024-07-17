package cn.tedu.DogWalkingAppointment.mapper;

import cn.tedu.DogWalkingAppointment.entity.Dog;

import java.util.List;


public interface DogMapper {
    Integer insert(Dog Dog);
    List<Dog> findByUid(Integer userId);
    Dog findByDogId(Integer dogId);
    Integer deleteByDogId(Integer dogId);
    List<Dog> findAllDog();
    Integer updateDogById(Dog dog);

    Integer changeIsReservedByAvailabilityId(Integer availabilityId);//实现预约
}
