# Philosophers

In this project, I learned the basics of threading a process. I learned how to make threads. I discovered the mutex.
Click here for a full [subject][1]

### Installing and running the program

1. Download or clone this repository

        git clone https://github.com/urumqinsky/Philosophers.git

2. `cd` into the directory and run `make`

        cd Philosophers/philo && make

3. run `./philo arg1 arg2 arg3 arg4 [arg5]`
    - number_of_philosophers: is the number of philosophers and also the number of forks.
    - time_to_die: is in milliseconds, if a philosopher doesn’t start eating ’time_to_die’ milliseconds after starting his last meal or the beginning of the simulation, it dies.
    - time_to_eat: is in milliseconds and is the time it takes for a philosopher to eat. During that time he will need to keep the two forks.
    - time_to_sleep: is in milliseconds and is the time the philosopher will spend sleeping.
    - number_of_times_each_philosopher_must_eat: argument is optional, if all philosophers eat at least ’number_of_times_each_philosopher_must_eat’ the simulation will stop. If not specified, the simulation will stop only at the death of a philosopher.

### Philo test
- Do not test with more than 200 philosophers
- Do not test with time_to_die or time_to_eat or time_to_sleep under 60 ms
- Test with 1 800 200 200, the philosopher should not eat and should die!
- Test with 5 800 200 200, no one should die!
- Test with 5 800 200 200 7, no one should die and the simulation should stop when all the philosopher has eaten atleast 7 times each.
- Test with 4 410 200 200, no one should die!
- Test with 4 310 200 100, a philosopher should die!- Test with 2 philosophers and check the different times (a death delayed by more than 10 ms is unacceptable).
- Test with your values to check all the rules. Check if a philosopher dies at the right time if they don't steal forks, etc.


[1]: https://github.com/urumqinsky/Philosophers/blob/main/en.subject.pdf
