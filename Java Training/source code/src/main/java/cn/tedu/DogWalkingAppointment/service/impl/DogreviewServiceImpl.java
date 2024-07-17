package cn.tedu.DogWalkingAppointment.service.impl;

import cn.tedu.DogWalkingAppointment.entity.CustomerReview;
import cn.tedu.DogWalkingAppointment.entity.DogAvailability;
import cn.tedu.DogWalkingAppointment.entity.DogReview;
import cn.tedu.DogWalkingAppointment.entity.User;
import cn.tedu.DogWalkingAppointment.mapper.DogReviewMapper;
import cn.tedu.DogWalkingAppointment.mapper.UserMapper;
import cn.tedu.DogWalkingAppointment.service.IDogreviewService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.util.Date;
import java.util.List;

@Service
public class DogreviewServiceImpl implements IDogreviewService {

    @Autowired
    private DogReviewMapper dogReviewMapper;
    @Autowired
    private UserMapper userMapper;

    @Override
    public void comment(DogReview d) {

        dogReviewMapper.addNewComment(d);

    }
    @Override
    public List<DogReview> getAllReviews(Integer dogId){
        List<DogReview> list= dogReviewMapper.showReviews(dogId);
        for(DogReview c:list){

        }
        return list;
    }

}

