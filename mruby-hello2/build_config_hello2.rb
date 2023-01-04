MRuby::Build.new do |conf|
  toolchain :gcc
  conf.gembox 'full-core'
  conf.gem "#{MRUBY_ROOT}/../mruby-hello2"

  enable_debug
  conf.enable_bintest
  conf.enable_test
end
