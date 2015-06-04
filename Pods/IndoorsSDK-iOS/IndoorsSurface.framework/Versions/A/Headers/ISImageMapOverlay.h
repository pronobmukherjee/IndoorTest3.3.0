#import <UIKit/UIKit.h>
#import "ISMapOverlay.h"

@interface ISImageMapOverlay : ISMapOverlay
@property (nonatomic, readonly) UIImageView *imageView;

- (instancetype)initWithOverlayBounds:(CGRect)overlayBounds;
@end
