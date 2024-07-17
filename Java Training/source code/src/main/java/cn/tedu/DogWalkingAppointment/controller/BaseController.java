package cn.tedu.DogWalkingAppointment.controller;

import cn.tedu.DogWalkingAppointment.ex.*;
import cn.tedu.DogWalkingAppointment.util.JsonResult;
import org.springframework.web.bind.annotation.ExceptionHandler;

import javax.servlet.http.HttpSession;

public class BaseController {
    @ExceptionHandler(ServiceException.class)
    public JsonResult<Void> handleException(Throwable e){
        JsonResult<Void> result = new JsonResult<Void>();
        if (e instanceof UsernameDuplicateException) {
            result.setState(4000);
            result.setMessage("用户名已经被占用");
        } else if (e instanceof InsertException) {
            result.setState(5000);
            result.setMessage("注册失败，请联系系统管理员");
        }else if (e instanceof UserNotFoundException) {
            result.setState(6000);
            result.setMessage("用户名不存在");
        } else if (e instanceof PasswordNotMatchException) {
            result.setState(7000);
            result.setMessage("密码错误");
        }else if (e instanceof UpdateException) {
            result.setState(5001);
            result.setMessage("更新错误，请联系超级管理员");
        }       e.printStackTrace();
        return result;
    }
    protected final Integer getUidFromSession(HttpSession session) {
        return (Integer) session.getAttribute("userId");
    }

    /**
     * 从HttpSession对象中获取用户名
     * @param session HttpSession对象
     * @return 当前登录的用户名
     */
    protected final String getUsernameFromSession(HttpSession session) {
        return (String) session.getAttribute("username");
    }
    protected final Integer getDogIdFromSession(HttpSession session) {
        return (Integer) session.getAttribute("dogId");
    }
}
