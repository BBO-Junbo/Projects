package cn.tedu.DogWalkingAppointment.mapper;

import cn.tedu.DogWalkingAppointment.entity.DogReview;

import java.util.List;

public interface DogReviewMapper {
    void addNewComment(DogReview dogReview);
    List<DogReview> showReviews(Integer dogId);
}
