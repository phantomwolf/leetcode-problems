#import <Foundation/Foundation.h>

#import "oop.h"

@implementation MyClass {
    NSInteger internalID;
}

@synthesize nickname = fakename;

- (NSString*)getFakename {
    return fakename;
}

- (NSString*)setFakename:(NSString*)name {
    self.fakename = name;
}

- (void)show {
    NSLog(@"name: %@, nickname: %@, publicID: %ld, internalID: %ld", _name, fakename, publicID, internalID);
}

@end


int main() {
    MyClass *obj = [[MyClass alloc] init];
    obj.name = @"foobar";
    [obj setNickname:@"dickey"];

    // Delegate
    id <Shower> shower = (id)obj;
    [(id)shower show];
}
