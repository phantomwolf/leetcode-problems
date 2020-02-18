#import <Foundation/Foundation.h>

int main() {
    // Assign a NSString to obj
    id obj = [[NSString alloc] init];
    obj = @"foo";
    NSLog(@"obj: %@", obj);
    // Assign a NSArray to obj
    NSArray *array = @[@386, @486, @586];
    obj = array;
    NSLog(@"obj: %@", obj);
}
