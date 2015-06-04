#import <UIKit/UIKit.h>
#import <Indoors/Indoors.h>
#import "IndoorsSurfaceEnums.h"
#import "ISMapScrollView.h"
#import "ISMapOverlay.h"
#import "ISImageMapOverlay.h"

@class ISIndoorsSurface;

@protocol IndoorsSurfaceViewDelegate <NSObject>

@optional

- (void)indoorsSurface:(ISIndoorsSurface *)surfaceView userDidSelectLocation:(IDSCoordinate *)location;
- (void)indoorsSurface:(ISIndoorsSurface *)surfaceView userDidTapLocation:(IDSCoordinate *)location;

@end

@interface ISIndoorsSurface : UIView

@property (nonatomic) id<IndoorsSurfaceViewDelegate> delegate;
@property (nonatomic, readonly) ISMapScrollView *mapScrollView;
@property (nonatomic) BOOL enableAutomaticFloorSelection;
@property (nonatomic) BOOL routeSnappingEnabled;

- (void)setBuildingForSurface:(IDSBuilding *)surfaceBuilding;
- (void)setFloorLevel:(NSInteger)floorLevel;
- (void)setSize:(CGRect)newFrame;
- (void)setMapCenterWithCoordinate:(IDSCoordinate *)coordinate;

- (void)letUserSelectLocationWithCalloutTitle:(NSString *)calloutTitle;
- (void)requireUserToSelectLocationWithCalloutTitle:(NSString *)calloutTitle;
- (void)cancelSelectLocation;

- (void)showPathWithPoints:(NSArray *)points color:(UIColor *)color lineWidth:(CGFloat)lineWidth;
- (void)showPathWithPoints:(NSArray *)points;
- (BOOL)hasActiveBuilding;
- (void)setZoneDisplayMode:(IndoorsSurfaceZoneDisplayModes)zoneDisplayMode;
- (void)setUserPositionDisplayMode:(IndoorsSurfaceUserPositionDisplayModes)userPositionDisplayMode;
- (void)setUserPositionIcon:(UIImage *)userPositionIcon;
- (void)setUserPositionDefaultIconColor:(UIColor *)color;
- (void)setUserPositionAccuracyCircleColor:(UIColor *)color;

- (void)hideAccuracy:(BOOL)shouldHideAccuracy;

@end
