#import <UIKit/UIKit.h>
#import <Indoors/Indoors.h>
#import "ISAnnotationView.h"

@interface ISPointAnnotationView : ISAnnotationView
- (instancetype)initWithCoordinate:(IDSCoordinate *)coordinate andFillColor:(UIColor *)fillColor;
@end
