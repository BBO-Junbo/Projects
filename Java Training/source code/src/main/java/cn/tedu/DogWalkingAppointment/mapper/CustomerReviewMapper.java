package cn.tedu.DogWalkingAppointment.mapper;

import cn.tedu.DogWalkingAppointment.entity.CustomerReview;

import java.util.List;

public interface CustomerReviewMapper {
    void addNewComment(CustomerReview customerReview);
    List<CustomerReview> showReviews(Integer customerId);
}
