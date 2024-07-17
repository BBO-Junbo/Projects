package cn.tedu.DogWalkingAppointment.controller;

import cn.tedu.DogWalkingAppointment.entity.Customer;
import cn.tedu.DogWalkingAppointment.entity.User;
import cn.tedu.DogWalkingAppointment.ex.InsertException;
import cn.tedu.DogWalkingAppointment.ex.UsernameDuplicateException;
import cn.tedu.DogWalkingAppointment.service.ICustomerService;
import cn.tedu.DogWalkingAppointment.service.IUsersService;
import cn.tedu.DogWalkingAppointment.util.JsonResult;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import javax.servlet.http.HttpSession;

@RestController
@RequestMapping("/users")
public class UserController extends BaseController{
    @Autowired
    private IUsersService usersService;
    @Autowired
    private ICustomerService customerService;
    @RequestMapping("reg")
    public JsonResult<Void> reg(User user) {
        // 创建返回值
        JsonResult<Void> result = new JsonResult<Void>();
            if(user.getRole().equals("C")){
                usersService.reg(user);
                Customer customer=new Customer();
                User u=usersService.getByName(user.getUsername());
                customer.setUserId(u.getUserId());
                customer.setCustomerName(user.getUsername());
                customerService.regc(customer);
            }else {
                usersService.reg(user);
            }

            result.setState(200);

        return result;
    }
    @RequestMapping("login")
    public JsonResult<User> login(String username, String password, String role, HttpSession session) {
        // 调用业务对象的方法执行登录，并获取返回值
        User data = usersService.login(username, password,role);
        session.setAttribute("userId",data.getUserId());
        session.setAttribute("username",data.getUsername());
        // 将以上返回值和状态码OK封装到响应结果中并返回
        return new JsonResult<User>(200,null, data);
    }
    @RequestMapping("change_password")
    public JsonResult<Void> changePassword(String oldPassword, String newPassword, HttpSession session) {
        // 调用session.getAttribute("")获取uid和username
        Integer userId = getUidFromSession(session);
        String username = getUsernameFromSession(session);
        // 调用业务对象执行修改密码
        usersService.changePassword(userId, username, oldPassword, newPassword);
        session.invalidate();
        // 返回成功
        return new JsonResult<Void>(200,null,null);
    }
    @RequestMapping ("get_by_uid")
    public JsonResult<User> getByUid(HttpSession session) {
        // 从HttpSession对象中获取uid
        Integer userId = getUidFromSession(session);
        // 调用业务对象执行获取数据
        User data = usersService.getByUid(userId);
        // 响应成功和数据
        return new JsonResult<>(200,null,data);
    }

    @RequestMapping("change_info")
    public JsonResult<Void> changeInfo(User user, HttpSession session) {
        // 从HttpSession对象中获取uid和username
        Integer userId = getUidFromSession(session);
        String username = getUsernameFromSession(session);
        // 调用业务对象执行修改用户资料
        usersService.changeInfo(userId, username, user);
        // 响应成功
        return new JsonResult<>(200,null,null);
    }
}
