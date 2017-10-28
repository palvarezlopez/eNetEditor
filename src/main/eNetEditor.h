#ifndef ENETEDITOR_H
#define ENETEDITOR_H

// QT Aplication
#include <QApplication>

// Debugger
#include <QDebug>

// QT Libraries
#include <QCheckBox>
#include <QColor>
#include <QCoreApplication>
#include <QDebug>
#include <QDialog>
#include <QDir>
#include <QDomDocument>
#include <QEventLoop>
#include <QFile>
#include <QFileDialog>
#include <QFont>
#include <QFrame>
#include <QGraphicsItem>
#include <QGraphicsPixmapItem>
#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsTextItem>
#include <QGraphicsView>
#include <QHBoxLayout>
#include <QInputDialog>
#include <QLabel>
#include <QLine>
#include <QListWidgetItem>
#include <QMainWindow>
#include <QMap>
#include <QMessageBox>
#include <QMouseEvent>
#include <QObject>
#include <QPainter>
#include <QPen>
#include <QPixmap>
#include <QProcess>
#include <QPushButton>
#include <QScrollBar>
#include <QSpacerItem>
#include <QSpinBox>
#include <QStack>
#include <QStaticText>
#include <QString>
#include <QStringList>
#include <QTableWidgetItem>
#include <QTextBrowser>
#include <QTextStream>
#include <QTime>
#include <QThread>
#include <QVector>
#include <QWheelEvent>
#include <QXmlStreamWriter>


// Declare class from QPlotLibrary
class QCPGraph;

// Declare main class
class eNetEditor;

// Declare class eNetEditorMainWindow
class eNetEditorMainWindow;

// Declare class eNetEditorDialog
class eNetEditorDialog;

// Declare class eNetEditorThread
class eNetEditorThread;

// Declare class eNetEditorLoadingDialog
class eNetEditorLoadingDialog;

// Declare eNetEditorMessages
class eNetEditorMessages;

// Declare processingDialog
class eNetEditorProcessingDialog;

// Declare eNetEditorConfiguration
class eNetEditorMainConfiguration;

// Declare netEditor sub-Dialogs
class eNetEditorAboutDialog;
class eNetEditorNewFileDialog;
class eNetEditorImportNetDialog;
class eNetEditorStatisticsDialog;

// Declare trafficLightConverter
class trafficLightConverter;

// Declare class eNetEditorImportNet
class eNetEditorImportNet;

// Declare projectConfiguration
class eNetEditorProjectConfiguration;

// Declare tools configurations
class eNetEditorToolConfiguration;
class cadytsToolConfiguration;
class dfRouterToolConfiguration;
class duaRouterToolConfiguration;
class jtrRouterToolConfiguration;
class netConvertToolConfiguration;
class netGenerateToolConfiguration;
class sumoToolConfiguration;

// Declare items itemsConfigurations
class eNetEditorItemConfiguration;
class nodeItemConfiguration;
class laneItemConfiguration;
class connectionItemConfiguration;
class prohibitionItemConfiguration;
class trafficLightItemConfiguration;
class routeItemConfiguration;
class busStopItemConfiguration;
class chargingStationItemConfiguration;
class vehicleTypeItemConfiguration;
class flowMeasureItemConfiguration;
class distributionFunctionItemConfiguration;
class eNetEditorTurnRatioConfiguration;
class turnRatioIntervalItemConfiguration;
class turnRatioItemConfiguration;
class eNetEditorDetectorConfiguration;
class inductionLoopsE1DetectorItemConfiguration;
class laneAreaE2DetectorItemConfiguration;
class multiEntryExitE3DetectorItemConfiguration;
class eNetEditorVehicleConfiguration;
class vehicleItemConfiguration;
class flowItemConfiguration;
class eNetEditorEdgeItemConfiguration;
class edgeItemConfiguration;
class edgeTypeItemConfiguration;

// Declare class enetEditorProject
class eNetEditorProject;

// Declare class for undo-redo actions
class undoRedoProject;

// Declare Parameter manager
class itemManagerProject;

// Declaration scene project
class eNetEditorScene;

// Declare Configuration Dialog
class eNetEditorConfigurationDialog;

// Declare Project Dialogs
class abstractProjectDialog;
class eNetEditorProjectDialog;
class scalaDialog;

// Declare eNetEditorDatabase
class eNetEditorDatabase;
class eNetEditorTable;

// Declare Table dialogs
class eNetEditorTableDialog;
class nodeTableDialog;
class laneTableDialog;
class connectionTableDialog;
class prohibitionTableDialog;
class trafficLightTableDialog;
class routeTableDialog;
class busStopTableDialog;
class chargingStationTableDialog;
class vehicleTypeTableDialog;
class flowMeasureTableDialog;
class distributionFunctionTableDialog;
class abstractTurnRatioDialog;
class turnRatioTableDialog;
class turnRatioIntervalTableDialog;
class abstractDetectorTableDialog;
class inductionLoopsE1DetectorTableDialog;
class laneAreaE2DetectorTableDialog;
class multiEntryExitE3DetectorTableDialog;
class abstractVehicleTableDialog;
class vehicleTableDialog;
class flowTableDialog;
class abstractEdgeTableDialog;
class edgeTableDialog;
class edgeTypeTableDialog;

// Declare item tables
class eNetEditorTable;
class nodeTable;
class laneTable;
class connectionTable;
class prohibitionTable;
class trafficLightTable;
class routeTable;
class busStopTable;
class chargingStationTable;
class vehicleTypeTable;
class flowMeasureTable;
class distributionFunctionTable;
class abstractTurnRatioTable;
class turnRatioTable;
class turnRatioIntervalTable;
class abstractDetectorTable;
class inductionLoopsE1DetectorTable;
class laneAreaE2DetectorTable;
class multiEntryExitE3DetectorTable;
class abstractVehicleTable;
class vehicleTable;
class flowTable;
class abstractEdgeTable;
class edgeTable;
class edgeTypeTable;

// Declare items Dialogs
class eNetEditorItemDialog;
class nodeItemDialog;
class laneItemDialog;
class connectionItemDialog;
class prohibitionItemDialog;
class trafficLightItemDialog;
class routeItemDialog;
class busStopItemDialog;
class chargingStationItemDialog;
class vehicleTypeItemDialog;
class distributionFunctionItemDialog;
class flowMeasureItemDialog;
class abstractTurnRatioItemDialog;
class turnRatioItemDialog;
class turnRatioIntervalDialog;
class abstractDetectorItemDialog;
class inductionLoopsE1DetectorItemDialog;
class laneAreaE2DetectorItemDialog;
class multiEntryExitE3DetectorItemDialog;
class abstractVehicleItemDialog;
class vehicleItemDialog;
class flowItemDialog;
class abstractEdgeItemDialog;
class edgeItemDialog;
class edgeTypeItemDialog;
class edgeVehicleTypesAllowedDialog;

// Declare Items
class eNetEditorItem;
class nodeItem;
class laneItem;
class connectionItem;
class prohibitionItem;
class trafficLightItem;
class routeItem;
class busStopItem;
class chargingStationItem;
class vehicleTypeItem;
class flowMeasureItem;
class distributionFunctionItem;
class abstractTurnRatioItem;
class turnRatioItem;
class turnRatioIntervalItem;
class abstractDetectorItem;
class inductionLoopsE1DetectorItem;
class laneAreaE2DetectorItem;
class multiEntryExitE3DetectorItem;
class abstractVehicleItem;
class vehicleItem;
class flowItem;
class abstractEdgeItem;
class edgeItem;
class edgeTypeItem;

// Declare eNetEditorToolDialog
class eNetEditorToolDialog;
class cadytsToolDialog;
class dfRouterToolDialog;
class duaRouterToolDialog;
class jtrRouterToolDialog;
class netConvertToolDialog;
class netGenerateToolDialog;
class sumoToolDialog;

// Declare eNetEditorTool
class eNetEditorTool;
class cadytsTool;
class dfRouterTool;
class duaRouterTool;
class jtrRouterTool;
class netConvertTool;
class netGenerateTool;
class sumoTool;

/// ENUMS

// FlagOperation enum
enum flagOperation
{
    flagOperationMoveNode,
    flagOperationAddOrRemoveNodeOrEdgeOrLane,
    flagOperationAddOrRemoveConnection,
    flagOperationAddOrRemoveProhibition,
    flagOperationAddOrRemoveTrafficLight,
    flagOperationAddOrRemoveRoute,
    flagOperationAddOrRemoveBusStop,
    flagOperationAddOrRemoveChargingStation,
    flagOperationAddOrRemoveDetector,
    flagOperationNoOperation,
};



/*! \enum nodeItemType
    All types of nodes that supports SUMO
*/
enum nodeItemType
{
    nodeItemTypePriority, /*!< Node type "priority" */
    nodeItemTypeTrafficLight, /*!<  Node type "traffic_light" */
    nodeItemTypeRightBeforeLeft, /*!<  Node type "right_before_left" */
    nodeItemTypeUnregulated, /*!<  Node type "unregulated" */
    nodeItemTypePriorityStop, /*!<  Node type "priority_stop" */
    nodeItemTypeTrafficLightUnregulated, /*!< Node type "traffic_light_unregulated" */
    nodeItemTypeAllwayStop, /*!< Node type "allway_stop" */
    nodeItemTypeRailSignal, /*!< Node type "rail_signal" */
};


// Declare edgeSpreadType
enum edgeSpreadType;


// Declare vehicleClass
enum vehicleClass;


/*! \enum Vehicle Shapes
    All vehicle Shapes that supports SUMO
*/
enum vehicleShape /** ARREGLAR **/
{
    vehicleShapeUnknown, /*!< Vehicle shape unknown */
    vehicleShapePedestrian, /*!< Vehicle shape pedestrian */
    vehicleShapeBicycle, /*!< Vehicle shape bicycle */
    vehicleShapeMotorcycle, /*!< Vehicle shape motorcycle */
    vehicleShapePassenger, /*!< Vehicle shape passenger */
    vehicleShapePassengerSedan, /*!< Vehicle shape passenger sedan */
    vehicleShapePassengerHatchback, /*!< Vehicle shape passenger hatchback */
    vehicleShapePassengerWagon, /*!< Vehicle shape passenger wagon */
    vehicleShapePassengerVan, /*!< Vehicle shape passenger van */
    vehicleShapeDelivery, /*!< Vehicle shape delivery */
    vehicleShapeTransport, /*!< Vehicle shape transport */
    vehicleShapeTransportSemitrailer, /*!< Vehicle shape transport semitrailer */
    vehicleShapeTransportTrailer, /*!< Vehicle shape transport trailer */
    vehicleShapeBus, /*!< Vehicle shape bus */
    vehicleShapeBusCity, /*!< Vehicle shape bus city */
    vehicleShapeBusFlexible, /*!< Vehicle shape bus flexible */
    vehicleShapeBusOverland, /*!< Vehicle shape bus overland */
    vehicleShapeRail, /*!< Vehicle shape rail */
    vehicleShapeRailLight, /*!< Vehicle shape rail light */
    vehicleShapeRailCity, /*!< Vehicle shape rail city */
    vehicleShapeRailSlow, /*!< Vehicle shape rail slow */
    vehicleShapeRailFast, /*!< Vehicle shape rail fast */
    vehicleShapeRailCargo, /*!< Vehicle shape rail cargo */
    vehicleShapeEvehicle /*!< Vehicle shape evehicle */
};


/*! \enum Connection direction
    All directions that a connection can take
*/
enum connectionDirection
{
    connectionDirectionStraight,
    connectionDirectionTurn,
    connectionDirectionLeft,
    connectionDirectionRight,
    connectionDirectionPartiallyLeft,
    connectionDirectionPartiallyRight,
    connectionDirectionNoDirection
};

// Declare enum connections state
enum connectionState
{
    connectionStateDeadEnd,
    connectionStateEqual,
    connectionStateMinorLink,
    connectionStateMayorLink,
    connectionStateControllerOff,
    connectionStateYellowFlashing,
    connectionStateYellowMinorLink,
    connectionStateYellowMajorLink,
    connectionStateRed,
    connectionStateGreenMinor,
    connectionStateGreenMajor
};

// Declare enum vehicle Emissions
enum vehicleEmission
{
    vehicleEmissionP_7_7
};

// Declare enum traffic Light Type
enum trafficLightType
{
    trafficLightTypeStatic,
    trafficLightTypeActuated
};

// Declare enum vehicle depart position
enum vehicleStartPos
{
    vehicleStartPosRandom,
    vehicleStartPosFree,
    vehicleStartPosRandomFree,
    vehicleStartPosBase,
    vehicleStartPosPwagSimple,
    vehicleStartPosPwagGeneric
};

// Declare enum Open Street Map Pixel/Meters
enum openStreetMapPixelMeter;

// Declare enum Open Street Map Scale
enum openStreetMapScale;

// Declare enum Open Street Map Degrees
enum openStreetMapDegree;

// Declare enum NetEditorAction
enum eNetEditorAction;

// Declare enum cadytsInputParameters
enum cadytsInputParameters;

// Declare enum cadytsOutputParameters
enum cadytsOutputParameters;

// Declare enum cadytsProcessingParameters
enum cadytsProcessingParameters;

// Declare enum dfRouterInputParameters
enum dfRouterInputParameters;

// Declare enum dfRouterOutputParameters
enum dfRouterOutputParameters;

// Declare enum dfRouterProcessingParameters
enum dfRouterProcessingParameters;

// Declar enum duaRouterInputParameters
enum duaRouterInputParameters;

// Declare enum duaRouterOutputParameters
enum duaRouterOutputParameters;

// Declar enum duaRouterProcessingParameters
enum duaRouterProcessingParameters;

// Declare enum jtrRouterInputParameters
enum jtrRouterInputParameters;

// Declare enum jtrRouterOutputParameters
enum jtrRouterOutputParameters;

// Declare enum jtrRouterProcessingParameters
enum jtrRouterProcessingParameters;

// Declare enum netConvertInputParameters
enum netConvertInputParameters;

// Declare enum netConvertOutputParameters
enum netConvertOutputParameters;

// Declare enum netConvertProcessingsParameters
enum netConvertProcessingsParameters;
// Declare enum netGenerateInputParameters
enum netGenerateInputParameters;

// Declare enum netGenerateOutputParameters
enum netGenerateOutputParameters;

// Declare enum netGenerateProcessingParameters
enum netGenerateProcessingParameters;

// Declare enum sumoInputParameters
enum sumoInputParameters;

// Declare enum sumoOutputParameters
enum sumoOutputParameters;

// Declare enum sumoProcessingParameters
enum sumoProcessingParameters;

// Declare enum eNetEditorItemDialogCloseType
enum eNetEditorItemDialogCloseType;

// Declare enum consoleMessageType
enum consoleMessageType;

// Declare class eNetEditor
class eNetEditor
{
public:

    eNetEditor();

    ~eNetEditor();

    int execute(const QApplication &application);

    const QString &geteNetEditorVersion() const;

    const QString &geteNetEditorRevision() const;


private:

    // Currently version of eNetEditor
    QString eNetEditorVersion;

    // Currently revision of eNetEditor
    QString eNetEditorRevision;
};

#endif //ENETEDITOR_H
