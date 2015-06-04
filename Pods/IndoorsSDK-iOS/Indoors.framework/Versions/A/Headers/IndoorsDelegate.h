//
//  IndoorsRequestDelegate.h
//  Indoors
//
//  Created by Gerhard Zeissl on 02.12.12.
//  Copyright (c) 2012 Indoors. All rights reserved.
//

#import <Foundation/Foundation.h>

@class IDSBuilding;
@class IndoorsError;

/**
 Delegate to retrieve buildings available from indoo.rs server.
 */
@protocol OnlineBuildingDelegate <NSObject>

/**
 @brief List of buildings available from indoo.rs server.
 
 @param buildings Array of IDSBuilding objects. The objects do not contain floors and tiles.
 */
- (void)setOnlineBuildings:(NSArray *)buildings;

- (void)getOnlineBuildingsFailWithError:(NSError *)error;

@end
    
/**
 @brief Delegate to retrieve calculated route.
 */
@protocol RoutingDelegate <NSObject>

/**
 @brief Called when requested route has been calculated.
 
 @param path Contains IDSCoordinate objects representing the path.
 */
- (void)setRoute:(NSArray *)path;

@end

/**
 @brief Delegate for progress of loading a building.
 */
@protocol LoadingBuildingDelegate <NSObject>

/**
 @brief Consequent calls are made until the building is loaded.
 
 @param progress Progress measured in percent.
 */
- (void)loadingBuilding:(NSNumber *)progress;
        
/**
 @brief Service finished processing building.
 
 @param building The loaded building.
 */
- (void)buildingLoaded:(IDSBuilding *)building;

/**
 @brief Callback when loading building failed
 */
- (void)loadingBuildingFailed;

@end

@protocol ZoneDelegate <NSObject>

- (void)setZones:(NSArray *)zones;

@end

/**
 @brief Retrieve information about the authentication status.
 */
@protocol IndoorsServiceDelegate <NSObject>

typedef NS_ENUM(NSUInteger, IDSBluetoothState) {
    IDSBluetoothStateAvailable,
    IDSBluetoothStateUnavailable
};

typedef NS_ENUM(NSUInteger, IDSLocationAuthorizationStatus) {
    IDSLocationAuthorizationStatusAllowed,
    IDSLocationAuthorizationStatusNotAllowed
};

/**
 @brief Client successfully registered to the indoors service.
 */
- (void)connected;

/**
 @brief Exceptions from this method will always have an error code set. See IndoorsErrorCode.h for details.
 */
- (void)onError:(IndoorsError *)indoorsError;

- (void)bluetoothStateDidChange:(IDSBluetoothState)bluetoothState;

- (void)locationAuthorizationStatusDidChange:(IDSLocationAuthorizationStatus)status;

@end

