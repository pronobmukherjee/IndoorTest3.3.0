#import <Foundation/Foundation.h>
#import <Indoors/Indoors.h>
#import "IndoorsSurfaceEnums.h"
#import "ISIndoorsSurface.h"

DEPRECATED_MSG_ATTRIBUTE("Please use ISIndoorsSurfaceViewController instead.")
/**
 @deprecated Deprecated in version 3.3.0
 */
@interface IndoorsSurfaceBuilder : NSObject

@property (nonatomic, readonly) ISIndoorsSurface *indoorsSurface;
@property (nonatomic) IndoorsSurfaceZoneDisplayModes zoneDisplayMode;

/**
 @brief Set display mode of the available zones in the map. The indoo.rs surface will highlight the zones with the given display mode.
 */
@property (nonatomic) IndoorsSurfaceUserPositionDisplayModes userPositionDisplayMode;
@property (nonatomic) UIImage *userPositionIcon;

/**
 @dreprecated Deprecated in version 3.3.0
 @brief Initialize IndoorsSurfaceBuilder. Used to present an indoo.rs map.
 
 @param indoorsBuilder An instance of IndoorsBuilder, you should intialize the instance with a valid API key and building ID.
 @param view The view the surface view will be added to as a subview. It will take full width and height of given view.
 */
- (instancetype)initWithIndoorsBuilder:(IndoorsBuilder*)indoorsBuilder inView:(UIView *)view;

- (void)registerForSurfaceLocationUpdates:(id<IndoorsLocationListener>)locationDelegate;
- (void)registerForSurfaceServiceUpdates:(id<IndoorsServiceDelegate, LoadingBuildingDelegate>)surfaceServiceDelegate;

- (void)showPathWithPoints:(NSArray *)points;
- (void)hideAccuracyView:(BOOL)shouldHideAccuracy;

- (void)build;

@end
