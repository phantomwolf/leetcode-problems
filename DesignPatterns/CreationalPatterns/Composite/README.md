# Composite
Compose objects into tree structures to represent part-whole hierarchies. Composite lets clients treat individual objects and compositions of objects uniformly.

## Motivation
考虑一个画流程图的软件(例如dia)，它允许用基本的组件(线、文件)来组建更大的组合组件，这些大组件又能组合起来形成更大的组合组件。

一个简单的实现是，为基本组件(Text, Line等)和组合组件(container)分别定义各自的类。但这个实现有一个问题，尽管基本组件和组合组件的大部分操作都相同，但代码还是得区别对待他们。这让系统更加复杂。

Composite模式的要点是，用一个虚类来同时代表基本组件和组合组件。

## Applicability
Use the Composite pattern when

- you want to represent part-whole hierarchies of objects.
- you want clients to be able to ignore the difference between compositions of objects and individual objects. Clients will treat all objects in the composite structure uniformly.

## 实现
问题：与child相关的操作，例如getChildren()、addChild()、removeChild()，应该写在基类Component里，还是只在Composite类里？若写在Component类里，但这些操作对Leaf类没有意义。

答：getChildren()可以放在Component基类里，默认返回空。这样对Leaf类来说也是有意义的：表明它们没有children。

对于addChild()、removeChild()操作就有些复杂：

1. 若定义在Component基类中，则提高了透明度，牺牲了安全：client代码可能会做些无意义的操作，比如给Leaf类addChild()
2. 若定义在Composite类中，则牺牲了透明度，这相当于在Component和Composite类里使用不同的接口。若client代码想调用addChild()、removeChild()，则需要先将其转换成Composite类型(还得确定其真实类型才能转换)，才能使用。

第2种方案的可能实现有dynamic_cast(带检查的downcast)，或者给Component基类加一个方法getComposite()，默认实现返回null，在Composite类中返回this。client代码中判断一下getComposite()的返回值，再进行不同的操作。

第1种方案，可以在Component基类里实现addChild()、removeChild()操作，默认实现是抛出异常，在Composite类里改写。
