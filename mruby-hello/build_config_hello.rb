MRuby::Build.new do |conf|
  toolchain :gcc
  conf.gembox 'full-core'
  conf.gem "#{MRUBY_ROOT}/../mruby-hello"

  enable_debug
  conf.enable_bintest
  conf.enable_test
end
