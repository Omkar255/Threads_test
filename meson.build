project('thread2', 'cpp',
  version : '0.1',
  default_options : ['warning_level=3', 'cpp_std=c++14'])

executable('thread2',
           'src/main.cpp',
           'src/new.cpp',
           dependencies : [
              dependency('threads')],
           install : true)
