# pom
Pomodoro kernel driver.

Defaults to 25 minutes.  Call msleep to sleep for 25 mins then panic the kernel.  This should be viewed as a prodoctivity enhancer.

Data loss may occur as a result of panicking the kernel, however, so you will have to develop your own procedure to ensure lack of data loss.  Please be aware, you should not let that interfere with your productivity.

Please note, this code is untested.  I've been trying to test it, but for some reason, my machine keeps crashing every 25 minutes or so...
