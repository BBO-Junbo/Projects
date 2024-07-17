package cn.tedu.DogWalkingAppointment.service;

import cn.tedu.DogWalkingAppointment.entity.Dog;

import java.util.List;

public interface IDogService {
    void addNewDog(Integer userId, String username, Dog dog);
    List<Dog> getByUid(Integer userId);
    Dog getByDogId(Integer dogId);
    void delete(Integer dogId, Integer userId, String username);
    List<Dog> getAllDog();
    Dog findByDogId(Integer dogId);
    void updateDogById(Dog dog);
}
