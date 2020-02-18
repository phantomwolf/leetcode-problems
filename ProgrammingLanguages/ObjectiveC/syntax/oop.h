
@interface MyClass : NSObject {
    // Member variables without property
    NSInteger publicID;
}

// property "name" will generate a instance variable "_name", getter method "name" and setter method "setName"
@property NSString *name;

@property NSString *nickname;

- (void)show;

@end

@protocol Shower

- (void)show;

@end
