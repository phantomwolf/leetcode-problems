# Decorator(Wrapper)
## Intent
Attach additional responsibilities to an object dynamically. Decorators provide a flexible alternative to subclassing for extending functionality.

动态地给object加功能(而不是通过subclass给class加功能)

## Motivation
Sometimes we want to add responsibilities to individual objects, not to an entire class.

## Applicability
Use Decorator

- to add responsibilities to individual objects dynamically and transparently, that is, without affecting other objects.
- for responsibilities that can be withdrawn.
- when extension by subclassing is impractical. Sometimes a large number of independent extensions are possible and would produce an explosion of subclasses to support every combination. Or a class definition may be hidden or otherwise unavailable for subclassing.

## Participants
- Component (VisualComponent): defines the interface for objects that can have responsibilities added to them dynamically.
- ConcreteComponent (TextView): defines an object to which additional responsibilities can be attached.
- Decorator: maintains a reference to a Component object and defines an interface that conforms to Component's interface.
- ConcreteDecorator (BorderDecorator, ScrollDecorator): adds responsibilities to the component.

## Consequences
1. More flexibility than static inheritance. With decorators, responsibilities can be added and removed at run-time simply by attaching and detaching them
2. Avoids feature-laden(装满feature) classes high up in the hierarchy. 避免大而全的class，无需在一个class里支持所有可预见的feature。目前不需要的feature不需要加进来。
3. 被装饰过的object是一个新的object，与原来的不一样。需要注意
4. Lots of little objects. The objects differ only in the way they are interconnected, not in their class or in the value of their variables.

## Implementation
1. 由于Decorator和ConcreteComponent都衍生于Component类，所以不应在Component基类中加入太多的数据存储，以免在大量使用Decorator时，造成大量开销。
