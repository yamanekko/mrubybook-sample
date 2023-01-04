FOO = 42
class Foo
  FOO = 63
end
class Bar < Foo
  FOO = 84
end

printf("FOO:: %d\n", FOO)
printf("Foo::FOO: %d\n", Foo::FOO)
printf("Bar::FOO: %d\n", Bar::FOO)

