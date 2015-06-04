#import <Foundation/Foundation.h>
#import "ISAnnotationView.h"

@class ISCalloutAnnotationView;

@protocol ISCalloutAnnotationViewDelegate <NSObject>
- (void)calloutAnnotationViewTouched:(ISCalloutAnnotationView *)calloutAnnotationView;
@end

@interface ISCalloutAnnotationView : ISAnnotationView
- (instancetype)initWithCoordinate:(IDSCoordinate *)coordinate text:(NSString *)text delegate:(id<ISCalloutAnnotationViewDelegate>)delegate;
@end
