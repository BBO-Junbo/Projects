package cn.tedu.DogWalkingAppointment.service;

import cn.tedu.DogWalkingAppointment.entity.DogAvailability;
import cn.tedu.DogWalkingAppointment.entity.DogReview;

import java.util.List;

public interface IDogreviewService {

    void comment(DogReview d);
    List<DogReview> getAllReviews(Integer dogId);
}
