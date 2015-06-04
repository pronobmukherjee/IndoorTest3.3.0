#import <UIKit/UIKit.h>
#import <Indoors/Indoors.h>

typedef enum {
    ISAnnotationViewPositionTop,
    ISAnnotationViewPositionRight,
    ISAnnotationViewPositionBottom,
    ISAnnotationViewPositionLeft,
    ISAnnotationViewPositionCenter
} ISAnnotationViewPosition;

@interface ISAnnotationView : UIView
@property (nonatomic) IDSCoordinate *coordinate;
@property (nonatomic) CGSize size;
@property (nonatomic, readonly) CGFloat widthRatio;
@property (nonatomic, readonly) CGFloat heightRatio;
@property (nonatomic, readonly) CGFloat zoomScale;
@property (nonatomic, readonly) ISAnnotationViewPosition position;

- (instancetype)initWithCoordinate:(IDSCoordinate *)coordinate position:(ISAnnotationViewPosition)position size:(CGSize)size NS_DESIGNATED_INITIALIZER;
- (void)setCoordinate:(IDSCoordinate *)coordinate;
- (void)setCoordinate:(IDSCoordinate *)coordinate animated:(BOOL)animated;
@end
