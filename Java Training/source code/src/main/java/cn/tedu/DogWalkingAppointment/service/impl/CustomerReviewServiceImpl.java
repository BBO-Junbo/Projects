package cn.tedu.DogWalkingAppointment.service.impl;

import cn.tedu.DogWalkingAppointment.entity.CustomerReview;
import cn.tedu.DogWalkingAppointment.entity.DogReview;
import cn.tedu.DogWalkingAppointment.mapper.CustomerReviewMapper;
import cn.tedu.DogWalkingAppointment.service.ICustomerReviewService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.util.Date;
import java.util.List;

@Service
public class CustomerReviewServiceImpl implements ICustomerReviewService {
    @Autowired
    CustomerReviewMapper customerReviewMapper;

    @Override
    public void comment(CustomerReview c) {
        customerReviewMapper.addNewComment(c);
    }

    @Override
    public List<CustomerReview> getAllReviews( Integer customerId){
        List<CustomerReview> list= customerReviewMapper.showReviews(customerId);
        for(CustomerReview c:list){

        }
        return list;
    }
}
