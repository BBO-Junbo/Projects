package cn.tedu.DogWalkingAppointment.service;

import cn.tedu.DogWalkingAppointment.entity.DogAvailability;
import cn.tedu.DogWalkingAppointment.entity.DogReview;

import java.util.List;

public interface IDogAvailabilityService {
    void addNewAvailability(Integer dogId,String username,DogAvailability dogAvailability);

    List<DogAvailability> getByDog_id(Integer dog_id);
    void deleteAvalibilityId(Integer avalibilityId);
    List<DogAvailability> getAllAvailability();
    void changeIsReserved(Integer aid);

}
