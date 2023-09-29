project('thread2', 'cpp',
  version : '0.1',
  default_options : ['warning_level=3', 'cpp_std=c++14'])

subdir('inc')
subdir('src')

executable('thread2',
  sources: sources,
  include_directories: incdir,
  dependencies : [
    dependency('threads')],
  install : true)
