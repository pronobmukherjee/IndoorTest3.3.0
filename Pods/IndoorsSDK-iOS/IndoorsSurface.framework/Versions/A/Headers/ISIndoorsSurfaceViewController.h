#import <UIKit/UIKit.h>

#import <IndoorsSurface/ISIndoorsSurface.h>

@protocol ISIndoorsSurfaceViewControllerDelegate;

/**
 @brief This is basically a wrapper for ISIndoorsSurface and handles loading and displaying of buildings for you.
 */
@interface ISIndoorsSurfaceViewController : UIViewController

@property (nonatomic, weak) id<ISIndoorsSurfaceViewControllerDelegate> delegate;
@property (nonatomic) IDSBuilding *building;

/**
 @brief The surface view used by the controller to display the building.
 */
@property (nonatomic, readonly) ISIndoorsSurface *surfaceView;

@property (nonatomic, readonly) IDSCoordinate *userLocation;
@property (nonatomic, readonly) float userOrientation;

/**
 @brief Uses the shared Indoors instance to load a building asynchronously and displays the initial floor in the surface view.
 
 @param buildingId ID of the building to load.
 */
- (void)loadBuildingWithBuildingId:(NSUInteger)buildingId;

@end

@protocol ISIndoorsSurfaceViewControllerDelegate <NSObject>

- (void)indoorsSurfaceViewController:(ISIndoorsSurfaceViewController *)indoorsSurfaceViewController isLoadingBuildingWithBuildingId:(NSUInteger)buildingId progress:(NSUInteger)progress;
- (void)indoorsSurfaceViewController:(ISIndoorsSurfaceViewController *)indoorsSurfaceViewController didFinishLoadingBuilding:(IDSBuilding *)building;
- (void)indoorsSurfaceViewController:(ISIndoorsSurfaceViewController *)indoorsSurfaceViewController didFailLoadingBuildingWithBuildingId:(NSUInteger)buildingId error:(NSError *)error;

@end