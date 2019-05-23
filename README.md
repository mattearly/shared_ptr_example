build:

    make

run:

    ./a.out

output:

    ------init with T(0)-------
    -> the value of coreData is 0
    -> the address of coreData stuff is 0x7fe8e0400670
    -> number of users holding coreData 1
    ------coreData.reset(new T(15), [this]...); -----
    constructor deleter called
    -> the value of coreData is 15
    -> the address of coreData stuff is 0x7fe8e0400680
    -> number of users holding coreData 1
    ------std::shared_ptr<T> sup = coreData;------
    -> the value of sup is 15
    -> the value of coreData is 15
    -> the address of coreData stuff is 0x7fe8e0400680
    -> number of users holding coreData 2
    -> the addres of sup is 0x7fe8e0400680
    ------*sup = 400-----
    -> the value of sup is 400
    -> the value of coreData is 400
    -> the address of coreData stuff is 0x7fe8e0400680
    -> number of users holding coreData 2
    ------sup.reset(new T(16), deleter);------
    -> the value of sup is 16
    -> the address of sup is 0x7fe8e0400670
    -> number of users holding sup 1
    -----
    -> the value of coreData is 400
    -> the address of coreData stuff is 0x7fe8e0400680
    -> number of users holding coreData 1
    ------coreData.reset(new T[2], [this]...);------
    reset custom deleter called
    -> the value of array coreData is 5 should be 5 
    -> the value of array coreData + 1 is 10 should be 10 
    -> the value of array coreData + 2 is 4 should be 4 
    -> the address of coreData stuff is 0x7fe8e0402a10
    -> number of users holding coreData 1
    ---------*(coreData.get() +1) = 20;--------
    -> the value of array coreData + 1 is 20 should be 20 
    ZZZZ exiting constructor demo.
    VAR custom deleter called
    ZZZZ exiting main program.
    custom deleter for arrays called