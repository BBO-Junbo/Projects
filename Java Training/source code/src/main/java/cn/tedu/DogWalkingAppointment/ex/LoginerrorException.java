package cn.tedu.DogWalkingAppointment.ex;

public class LoginerrorException extends ServiceException{
    public LoginerrorException() {
    }

    public LoginerrorException(String message) {
        super(message);
    }

    public LoginerrorException(String message, Throwable cause) {
        super(message, cause);
    }

    public LoginerrorException(Throwable cause) {
        super(cause);
    }

    public LoginerrorException(String message, Throwable cause, boolean enableSuppression, boolean writableStackTrace) {
        super(message, cause, enableSuppression, writableStackTrace);
    }
}
