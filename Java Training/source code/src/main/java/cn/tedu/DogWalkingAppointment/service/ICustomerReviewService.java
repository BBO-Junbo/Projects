package cn.tedu.DogWalkingAppointment.service;

import cn.tedu.DogWalkingAppointment.entity.CustomerReview;

import java.util.List;

public interface ICustomerReviewService {
    void comment(CustomerReview customerReview);
    List<CustomerReview> getAllReviews(Integer customerId);
}
