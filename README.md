# VSLEEP

vsleep is a verbose alternative to the classic shell command sleep.  It
supports times in seconds, minutes, hours, days, and fractions and sums of
any combination of supported units.  Its intended use case is to enable users
to quickly determine how much time is left before the command finishes.  This
makes it a convenient timer--where the alarm could be as simple as toggling
play or pause on music, altering screen brightness, or any other command users
wish to run.  It may or may not build on systems other than Linux.  

# Technology
C, Make, Man pages

# Build instructions
Clone the repository.  Check the config.mk and update any variables to reflect
where you want things installed on your system.  Install a C compiler if one
isn't already present, then run: 

    make

    sudo make install

# Examples
    vsleep 3h 60s

    vlseep 2d 1m 3s

    vsleep 1d 36h 27m 14.5s

    vsleep 0.5s && mpc pause

