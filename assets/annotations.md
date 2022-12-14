https://gist.github.com/petermunro/735830c16cf1ddc274de
https://gist.github.com/petermunro/14668fb9020398b77bf5
https://joyeecheung.github.io/blog/2021/08/27/binding-v8-on-an-m1-macbook/
https://github.com/danbev/learning-libuv.git
https://nikhilm.github.io/uvbook/basics.html

https://medium.com/dkatalis/nodejs-architecture-relationship-between-libuv-v8-and-js-7dce74cf1c51
https://v8.dev/docs/d8
https://gist.github.com/kevincennis/0cd2138c78a07412ef21
https://github.com/andreburgaud/docker-v8
https://www.youtube.com/watch?v=5fWIf2A6Z_s - Lemon
https://youtu.be/0XZEaaAqjCA =  Building a JavaScript Runtime dotJS
https://youtu.be/wz7Znu6tqFw = Native Script
https://stackoverflow.com/questions/49811043/relationship-between-event-loop-libuv-and-v8-engine
https://codeahoy.com/learn/libuv/ch1/#how-to-install-libvu + callbacks
https://github.com/kristrev/libuv-multiple-loops/blob/master/libuv-test.c = multi uvs
https://gist.github.com/ngot/4e363c08c1a912f3f10fda882a9e3956 - v8 multithread

g++ -I. -Iinclude samples/hello-world.cc -o hello_world -lv8_monolith -Lout.gn/x64.release.sample/obj/ -pthread -std=c++14 -DV8_COMPRESS_POINTERS
cp out.gn/x64.release.sample/icudtl.dat .

g++ -I. -Iinclude samples/hello-world.cc -o hello_world -lv8_monolith -Lout.gn/arm64.release.sample/obj/ -pthread -std=c++14 -DV8_COMPRESS_POINTERS

branch: 881fc0496c


UV_LIB=$(UV_PATH)/build/libuv_a.a



https://github.com/manuel/8ttpd
https://www.reddit.com/r/node/comments/cluorc/comment/evyk21d/?utm_source=share&utm_medium=web2x&context=3
https://www.reddit.com/r/node/comments/cluorc/what_are_the_differences_between_nodes_event_loop/
https://github.com/nodejs/help/issues/3124
https://stackoverflow.com/questions/9433864/whats-the-difference-between-libev-and-libevent
https://gist.github.com/krikulis/793194 - http with libevent

libevent
  mkdir build && cd build
  cmake .. -DOPENSSL_ROOT_DIR=/usr/local/opt/openssl -DOPENSSL_LIBRARIES=/usr/local/opt/openssl/lib
  make
  make verify #optional

https://github.com/mikelxc/Workarounds-for-ARM-mac#installation

cd .. rm -rf build
mkdir build && cd build
cmake \
  -DCMAKE_SYSTEM_PROCESSOR=ARM \
  -DCMAKE_OSX_ARCHITECTURES=arm \
  -DCMAKE_CXX_COMPILER=/usr/bin/g++ \
  -DCMAKE_C_COMPILER=/usr/bin/gcc ..

  -DOPENSSL_ROOT_DIR=/usr/local/opt/openssl \
  -DOPENSSL_LIBRARIES=/usr/local/opt/openssl/lib

make -DCMAKE_CXX_COMPILER=/usr/bin/g++ -DCMAKE_C_COMPILER=/usr/bin/gcc ..


https://gist.github.com/tejom/d335a6ab1ac86b45f149e5c10e14b132 -> add console.log

gcc -v -E -x c++ -
  -> list all libraries for vscode

https://github.com/huruji/v8-with-libuv/tree/main/src

Working snap: https://gitpod.io#snapshot/6a277626-548d-4a6b-a1fc-73eb2f14de5c


--
Script:
- Let's get started then
- I'll be using the gitpod with you
- First go to the GitHub repo, leave a star and open it on your browser
- Login in with your GitHub profile
- run ./start.sh
- make
- ./capivara index.js

- Steps we'll do now
  - checkout all examples so you can run each example independently
  - I've prepared a template to focus only what's relevant for this demo but I'll walk you throughout the whole thing
  - the template now is read as a JS file and interpret it on V8
  - setting up libuv listening for events
  - You'll:
    - implement our own console.log
    - implement our own setTimeout and setInterval
    - spin up a thread and execute some code
    - create a complex js file using promises, timers, and more to check if our own nodejs is working


- Show all examples
- Show scripts in case you wanna compile yourself

- Template:
  - V8 with hello world working (print) and read file and UV
    - index.js with only print
    - show that setTimeout and setInterval don't exist

- creating timer.hpp
  on index.js
      interval = 0
      sleep = 100
      timeout(sleep, interval, () => {
        print('1 ' + new Date().toISOString());
      });

      interval = 200
      sleep = 100
      timeout(sleep, interval, () => {
        print('1 ' + new Date().toISOString());
      });

  show examples/uv-timers needs a event loop
  show WaitForEvents
  touch timer.hpp

  Initialize
    all
  Timeout
    all until callback->IsFunction
    print delay, repeat and callback
      printf("delay %lld, repeat %lld\n", delay, repeat);
      v8::String::Utf8Value str(isolate, args[2]);
      printf("%s\n", *str);
  capivara
    InitializeProgram
      add timer initialization

  ->  show callbacks being passed as params

  OnTimerCb
    all
  Timeout
    initialize uv timers

  -> setTimeout should work now
  index.js
    const setTimeout = (ms, cb) => timeout(ms, 0, cb);
    const setInterval = (ms, cb) => timeout(0, ms, cb);
    const setTimeoutAsync = (ms) => new Promise(resolve => setTimeout(ms, resolve))

    ;(async function asyncFn() {
      print(new Date().toISOString(), 'waiting a sec...')
      await setTimeoutAsync(1000)
      print(new Date().toISOString(), 'waiting a sec...')
      await setTimeoutAsync(1000)
      print(new Date().toISOString(), 'finished at')
    })()

- all threads work in Node.js - Worker Threads
  - thread all

  capivara
    add thread binding

Conclusions
