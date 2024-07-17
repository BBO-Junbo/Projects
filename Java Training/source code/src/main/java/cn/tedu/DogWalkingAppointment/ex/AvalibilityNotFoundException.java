package cn.tedu.DogWalkingAppointment.ex;

public class AvalibilityNotFoundException extends ServiceException{
    public AvalibilityNotFoundException() {
    }

    public AvalibilityNotFoundException(String message) {
        super(message);
    }

    public AvalibilityNotFoundException(String message, Throwable cause) {
        super(message, cause);
    }

    public AvalibilityNotFoundException(Throwable cause) {
        super(cause);
    }

    public AvalibilityNotFoundException(String message, Throwable cause, boolean enableSuppression, boolean writableStackTrace) {
        super(message, cause, enableSuppression, writableStackTrace);
    }
}
