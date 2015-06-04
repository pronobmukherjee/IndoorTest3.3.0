#import <UIKit/UIKit.h>

#import <Indoors/Indoors.h>

@interface ISMapOverlay : UIView
@property (nonatomic) CGRect overlayBounds; // in mm.
@property (nonatomic, readonly) CGFloat widthRatio;
@property (nonatomic, readonly) CGFloat heightRatio;
@property (nonatomic, readonly) CGFloat zoomScale;

- (instancetype)initWithOverlayBounds:(CGRect)overlayBounds;
@end
