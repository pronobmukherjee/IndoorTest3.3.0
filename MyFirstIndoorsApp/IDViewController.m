//
//  IDViewController.m
//  MyFirstIndoorsApp
//
//  Copyright (c) 2015 indoo.rs GmbH. All rights reserved.
//

#import "IDViewController.h"
#import <Indoors/Indoors.h>
#import <IndoorsSurface/ISIndoorsSurfaceViewController.h>

@interface IDViewController () <IndoorsServiceDelegate, ISIndoorsSurfaceViewControllerDelegate, RoutingDelegate, ZoneDelegate>

@end

@implementation IDViewController {
    ISIndoorsSurfaceViewController *_indoorsSurfaceViewController;
}

- (void)viewDidLoad
{
    [super viewDidLoad];
    
    __unused Indoors *indoors = [[Indoors alloc] initWithLicenseKey:@"cf81642a-ca39-4bd1-ae09-b3bb6a377f76" andServiceDelegate:self]; // REPLACE WITH YOUR API KEY
    
    _indoorsSurfaceViewController = [[ISIndoorsSurfaceViewController alloc] init];
    _indoorsSurfaceViewController.delegate = self;
    
    [self addSurfaceAsChildViewController];
    _indoorsSurfaceViewController.surfaceView.routeSnappingEnabled = YES;
    [_indoorsSurfaceViewController loadBuildingWithBuildingId:446756412]; // REPLACE WITH YOUR BUILDING ID
    [_indoorsSurfaceViewController.surfaceView setZoneDisplayMode:IndoorsSurfaceZoneDisplayModeUserCurrentLocation];
    //    [_indoorsSurfaceViewController.surfaceView setZoneDisplayMode:IndoorsSurfaceZoneDisplayModeAllAvailable];
    [_indoorsSurfaceViewController.surfaceView setUserPositionDisplayMode:IndoorsSurfaceUserPositionDisplayModeDefault];
}

- (void)addSurfaceAsChildViewController
{
    [self addChildViewController:_indoorsSurfaceViewController];
    _indoorsSurfaceViewController.view.frame = self.view.frame;
    [self.view addSubview:_indoorsSurfaceViewController.view];
    [_indoorsSurfaceViewController didMoveToParentViewController:self];
}

#pragma mark - ISIndoorsSurfaceViewControllerDelegate

- (void)indoorsSurfaceViewController:(ISIndoorsSurfaceViewController *)indoorsSurfaceViewController isLoadingBuildingWithBuildingId:(NSUInteger)buildingId progress:(NSUInteger)progress
{
    NSLog(@"Building loading progress: %lu", (unsigned long)progress);
}

- (void)indoorsSurfaceViewController:(ISIndoorsSurfaceViewController *)indoorsSurfaceViewController didFinishLoadingBuilding:(IDSBuilding *)building
{
    NSLog(@"Building loaded successfully!");
}

- (void)indoorsSurfaceViewController:(ISIndoorsSurfaceViewController *)indoorsSurfaceViewController didFailLoadingBuildingWithBuildingId:(NSUInteger)buildingId error:(NSError *)error
{
    NSLog(@"Loading building failed with error: %@", error);
    
    [[[UIAlertView alloc] initWithTitle:error.localizedDescription message:error.localizedFailureReason delegate:nil cancelButtonTitle:nil otherButtonTitles:@"ok", nil] show];
}

#pragma mark - IndoorsServiceDelegate

- (void)connected
{
    
}

- (void)onError:(IndoorsError *)indoorsError
{
    
}

- (void)locationAuthorizationStatusDidChange:(IDSLocationAuthorizationStatus)status
{
    
}

- (void)bluetoothStateDidChange:(IDSBluetoothState)bluetoothState
{
    
}

- (void)calculateRoute:(IDSCoordinate *)userPosition
{
    IDSCoordinate* start = [[IDSCoordinate alloc] initWithX:userPosition.x andY:userPosition.y andFloorLevel:userPosition.z];
    IDSCoordinate* end = [[IDSCoordinate alloc] initWithX:38268 andY:7152 andFloorLevel:userPosition.z];
    
    [[Indoors instance] routeFromLocation:start toLocation:end delegate:self];
}

// ...

#pragma mark - RoutingDelegate
- (void)setRoute:(NSArray *)path
{
    [_indoorsSurfaceViewController.surfaceView showPathWithPoints:path];
}

#pragma mark - ZoneDelegate
- (void)setZones:(NSArray*)zones
{
    
}

@end