#import <UIKit/UIKit.h>
#import <Indoors/IDSCoordinate.h>
#import <Indoors/IDSDefaultMap.h>
#import "ISAnnotationView.h"
#import "IndoorsSurfaceEnums.h"
#import "ISMapOverlay.h"

@class ISMapScrollView;

@protocol ISMapScrollViewDelegate <NSObject>
@optional
- (void)mapScrollView:(ISMapScrollView *)mapScrollView userDidSelectLocation:(IDSCoordinate *)location;
- (void)mapScrollView:(ISMapScrollView *)mapScrollView userDidTapLocation:(IDSCoordinate *)location;
@end

@interface ISMapScrollView : UIScrollView <UIScrollViewDelegate>

@property (nonatomic) IDSDefaultMap *map;
@property (nonatomic) id<ISMapScrollViewDelegate> mapScrollViewDelegate;
@property (nonatomic) NSArray *currentRoutingPath;
@property (nonatomic) IDSCoordinate *userCurrentLocation;
@property (nonatomic) NSInteger userCurrentFloorLevel;

- (void)letUserSelectLocationWithCalloutTitle:(NSString *)title;
- (void)requireUserToSelectLocationWithCalloutTitle:(NSString *)title;
- (void)cancelSelectLocation;

- (void)setRoutingPath:(NSArray *)path;
- (void)setRoutingPath:(NSArray *)path withColor:(UIColor *)color lineWidth:(CGFloat)lineWidth;
- (void)clearRouting;

- (void)setUserPosition:(IDSCoordinate *)coordinate;
- (void)setUserOrientation:(float)orientation;
- (void)setUserLocationHidden:(BOOL)isHidden;
- (void)setMapCenterWithCoordinate:(IDSCoordinate *)coordinate;
- (void)zoomToMapRect:(CGRect)rect animated:(BOOL)animated;

- (void)addOverlay:(ISMapOverlay *)overlay toFloorLevel:(NSInteger)floorLevel;
- (void)removeOverlay:(ISMapOverlay *)overlay;
- (void)addAnnotation:(ISAnnotationView *)annotationView;
- (void)removeAnnotation:(ISAnnotationView *)annotationView;
- (void)setZoneDisplayMode:(IndoorsSurfaceZoneDisplayModes)zoneDisplayMode;
- (void)setUserPositionDisplayMode:(IndoorsSurfaceUserPositionDisplayModes)userPositionDisplayMode;
- (void)setUserPositionIcon:(UIImage *)userPositionIcon;
- (void)setUserPositionDefaultIconColor:(UIColor *)color;
- (void)setUserPositionAccuracyCircleColor:(UIColor *)color;
- (void)didReceiveWeakSignal;

- (IDSCoordinate *)coordinateForPoint:(CGPoint)point;
- (CGPoint)pointForCoordinate:(IDSCoordinate *)coordinate;
@end
