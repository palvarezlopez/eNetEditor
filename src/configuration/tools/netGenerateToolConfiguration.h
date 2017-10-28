#ifndef NETGENERATETOOLCONFIGURATION_H
#define NETGENERATETOOLCONFIGURATION_H

#include "eNetEditorToolConfiguration.h"


class netGenerateToolConfiguration : public eNetEditorToolConfiguration
{
public:

    netGenerateToolConfiguration();

    ~netGenerateToolConfiguration();


    // GET FUNCTIONS

    /**
        @brief Get
        @return true if X is enabled, false in other case
        @details Get
    */
    bool getNetGenerateDefaultGrid() const;

    /**
        @brief Get
        @return qreal with the
        @details Get
    */
    int getNetGenerateDefaultGridNumber() const;

    /**
        @brief Get
        @return qreal with the
        @details Get
    */
    qreal getNetGenerateDefaultGridLength() const;

    /**
        @brief Get
        @return qreal with the
        @details Get
    */
    int getNetGenerateDefaultGridXNumber() const;

    /**
        @brief Get
        @return qreal with the
        @details Get
    */
    int getNetGenerateDefaultGridYNumber() const;

    /**
        @brief Get
        @return qreal with the
        @details Get
    */
    qreal getNetGenerateDefaultGridXLength() const;

    /**
        @brief Get
        @return qreal with the
        @details Get
    */
    qreal getNetGenerateDefaultGridYLength() const;

    /**
        @brief Get
        @return qreal with the
        @details Get
    */
    qreal getNetGenerateDefaultGridAttachLength() const;

    /**
        @brief Get
        @return true if X is enabled, false in other case
        @details Get
    */
    bool getNetGenerateDefaultSpider() const;

    /**
        @brief Get
        @return qreal with the
        @details Get
    */
    int getNetGenerateDefaultSpiderArmNumber() const;

    /**
        @brief Get
        @return qreal with the
        @details Get
    */
    int getNetGenerateDefaultSpiderCircleNumber() const;

    /**
        @brief Get
        @return qreal with the
        @details Get
    */
    qreal getNetGenerateDefaultSpiderSpaceRadius() const;

    /**
        @brief Get
        @return true if X is enabled, false in other case
        @details Get
    */
    bool getNetGenerateDefaultSpiderOmitCenter() const;

    /**
        @brief Get
        @return true if X is enabled, false in other case
        @details Get
    */
    bool getNetGenerateDefaultRand() const;

    /**
        @brief Get
        @return qreal with the
        @details Get
    */
    int getNetGenerateDefaultRandIterations() const;

    /**
        @brief Get
        @return qreal with the
        @details Get
    */
    qreal getNetGenerateDefaultRandBidiProbability() const;

    /**
        @brief Get
        @return qreal with the
        @details Get
    */
    qreal getNetGenerateDefaultRandMaxDistance() const;

    /**
        @brief Get
        @return qreal with the
        @details Get
    */
    qreal getNetGenerateDefaultRandMinDistance() const;

    /**
        @brief Get
        @return qreal with the
        @details Get
    */
    qreal getNetGenerateDefaultRandMinAngle() const;

    /**
        @brief Get
        @return qreal with the
        @details Get
    */
    int getNetGenerateDefaultRandNumTries() const;

    /**
        @brief Get
        @return qreal with the
        @details Get
    */
    qreal getNetGenerateDefaultRandConnectivity() const;

    /**
        @brief Get
        @return qreal with the
        @details Get
    */
    qreal getNetGenerateDefaultRandNeighborDist1() const;

    /**
        @brief Get
        @return qreal with the
        @details Get
    */
    qreal getNetGenerateDefaultRandNeighborDist2() const;

    /**
        @brief Get
        @return qreal with the
        @details Get
    */
    qreal getNetGenerateDefaultRandNeighborDist3() const;

    /**
        @brief Get
        @return qreal with the
        @details Get
    */
    qreal getNetGenerateDefaultRandNeighborDist4() const;

    /**
        @brief Get
        @return qreal with the
        @details Get
    */
    qreal getNetGenerateDefaultRandNeighborDist5() const;

    /**
        @brief Get
        @return qreal with the
        @details Get
    */
    qreal getNetGenerateDefaultRandNeighborDist6() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    const QString &getNetGenerateDefaultOutputPrefix() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    const QString &getNetGenerateDefaultOutputFile() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    const QString &getNetGenerateDefaultPlainOutputPrefix() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    const QString &getNetGenerateDefaultJunctionsJoinOutput() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    const QString &getNetGenerateDefaultAmitranOutput() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    const QString &getNetGenerateDefaultMatsimOutput() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    const QString &getNetGenerateDefaultOpendriveOutput() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    const QString &getNetGenerateDefaultDlrNavteqOutput() const;

    /**
        @brief Get
        @return true if X is enabled, false in other case
        @details Get
    */
    bool getNetGenerateDefaultOutputStreetNames() const;

    /**
        @brief Get
        @return true if X is enabled, false in other case
        @details Get
    */
    bool getNetGenerateDefaultOutputOriginalNames() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    const QString &getNetGenerateDefaultStreetSignOutput() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    const QString &getNetGenerateDefaultTlsSet() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    const QString &getNetGenerateDefaultTlsUnset() const;

    /**
        @brief Get
        @return true if X is enabled, false in other case
        @details Get
    */
    bool getNetGenerateDefaultTlsGuess() const;

    /**
        @brief Get
        @return true if X is enabled, false in other case
        @details Get
    */
    bool getNetGenerateDefaultTlsGuessJoining() const;

    /**
        @brief Get
        @return true if X is enabled, false in other case
        @details Get
    */
    bool getNetGenerateDefaultTlsJoin() const;

    /**
        @brief Get
        @return qreal with the
        @details Get
    */
    int getNetGenerateDefaultTlsGreenTime() const;

    /**
        @brief Get
        @return qreal with the
        @details Get
    */
    qreal getNetGenerateDefaultTlsYellowMinDecel() const;

    /**
        @brief Get
        @return true if X is enabled, false in other case
        @details Get
    */
    bool getNetGenerateDefaultTlsYellowPatchSmall() const;

    /**
        @brief Get
        @return qreal with the
        @details Get
    */
    int getNetGenerateDefaultTlsYellowTime() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    const QString &getNetGenerateDefaultTlsHalfOffset() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    const QString &getNetGenerateDefaultTlsQuarterOffset() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    const QString &getNetGenerateDefaultTlsDefaultType() const;

    /**
        @brief Get
        @return qreal with the
        @details Get
    */
    qreal getNetGenerateDefaultKeepEdgesMinSpeed() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    const QString &getNetGenerateDefaultRemoveEdgesExplicit() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    const QString &getNetGenerateDefaultKeepEdgesExplicit() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    const QString &getNetGenerateDefaultKeepEdgesInputFile() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    const QString &getNetGenerateDefaultKeepEdgesInBoundary() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    const QString &getNetGenerateDefaultKeepEdgesInGeoBoundary() const;

    /**
        @brief Get
        @return true if X is enabled, false in other case
        @details Get
    */
    bool getNetGenerateDefaultKeepNodesUnregulated() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    const QString &getNetGenerateDefaultKeepNodesUnregulatedExplicit() const;

    /**
        @brief Get
        @return true if X is enabled, false in other case
        @details Get
    */
    bool getNetGenerateDefaultKeepNodesUnregulatedDistrictNodes() const;

    /**
        @brief Get
        @return true if X is enabled, false in other case
        @details Get
    */
    bool getNetGenerateDefaultNoInternalLinks() const;

    /**
        @brief Get
        @return true if X is enabled, false in other case
        @details Get
    */
    bool getNetGenerateDefaultNoTurnarounds() const;

    /**
        @brief Get
        @return true if X is enabled, false in other case
        @details Get
    */
    bool getNetGenerateDefaultNoTurnaroundsTls() const;

    /**
        @brief Get
        @return true if X is enabled, false in other case
        @details Get
    */
    bool getNetGenerateDefaultNoLeftConnections() const;

    /**
        @brief Get
        @return true if X is enabled, false in other case
        @details Get
    */
    bool getNetGenerateDefaultOffsetDisableNormalization() const;

    /**
        @brief Get
        @return qreal with the
        @details Get
    */
    qreal getNetGenerateDefaultOffsetX() const;

    /**
        @brief Get
        @return qreal with the
        @details Get
    */
    qreal getNetGenerateDefaultOffsetY() const;

    /**
        @brief Get
        @return true if X is enabled, false in other case
        @details Get
    */
    bool getNetGenerateDefaultFlipYAxis() const;

    /**
        @brief Get
        @return true if X is enabled, false in other case
        @details Get
    */
    bool getNetGenerateDefaultRoundaboutsGuess() const;

    /**
        @brief Get
        @return true if X is enabled, false in other case
        @details Get
    */
    bool getNetGenerateDefaultLefthand() const;

    /**
        @brief Get
        @return true if X is enabled, false in other case
        @details Get
    */
    bool getNetGenerateDefaultJunctionsJoin() const;

    /**
        @brief Get
        @return qreal with the
        @details Get
    */
    qreal getNetGenerateDefaultJunctionsJoinDist() const;

    /**
        @brief Get
        @return qreal with the
        @details Get
    */
    int getNetGenerateDefaultJunctionsCornerDetail() const;

    /**
        @brief Get
        @return true if X is enabled, false in other case
        @details Get
    */
    bool getNetGenerateDefaultCheckLaneFoesRoundabout() const;

    /**
        @brief Get
        @return true if X is enabled, false in other case
        @details Get
    */
    bool getNetGenerateDefaultCheckLaneFoesAll() const;

    /**
        @brief Get
        @return true if X is enabled, false in other case
        @details Get
    */
    bool getNetGenerateDefaultSidewalksGuess() const;

    /**
        @brief Get
        @return qreal with the
        @details Get
    */
    qreal getNetGenerateDefaultSidewalksGuessMaxSpeed() const;

    /**
        @brief Get
        @return qreal with the
        @details Get
    */
    qreal getNetGenerateDefaultSidewalksGuessMinSpeed() const;

    /**
        @brief Get
        @return true if X is enabled, false in other case
        @details Get
    */
    bool getNetGenerateDefaultSidewalksGuessFromPermissions() const;

    /**
        @brief Get
        @return true if X is enabled, false in other case
        @details Get
    */
    bool getNetGenerateDefaultCrossingsGuess() const;

    /**
        @brief Get
        @return qreal with the
        @details Get
    */
    qreal getNetGenerateDefaultTlsJoinDist() const;

    /**
        @brief Get
        @return qreal with the
        @details Get
    */
    int getNetGenerateDefaultDefaultLanenumber() const;

    /**
        @brief Get
        @return qreal with the
        @details Get
    */
    qreal getNetGenerateDefaultDefaultSpeed() const;

    /**
        @brief Get
        @return qreal with the
        @details Get
    */
    int getNetGenerateDefaultDefaultPriority() const;

    /**
        @brief Get
        @return qreal with the
        @details Get
    */
    qreal getNetGenerateDefaultDefaultSidewalkWidth() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    const QString &getNetGenerateDefaultDefaultJunctionType() const;

    /**
        @brief Get
        @return true if X is enabled, false in other case
        @details Get
    */
    bool getNetGenerateDefaultVerbose() const;

    /**
        @brief Get
        @return true if X is enabled, false in other case
        @details Get
    */
    bool getNetGenerateDefaultPrintOptions() const;

    /**
        @brief Get
        @return true if X is enabled, false in other case
        @details Get
    */
    bool getNetGenerateDefaultHelp() const;

    /**
        @brief Get
        @return true if X is enabled, false in other case
        @details Get
    */
    bool getNetGenerateDefaultVersion() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    const QString &getNetGenerateDefaultXmlValidation() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    const QString &getNetGenerateDefaultXmlValidationNet() const;

    /**
        @brief Get
        @return true if X is enabled, false in other case
        @details Get
    */
    bool getNetGenerateDefaultNoWarnings() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    const QString &getNetGenerateDefaultLog() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    const QString &getNetGenerateDefaultMessageLog() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    const QString &getNetGenerateDefaultErrorLog() const;

    /**
        @brief Get
        @return true if X is enabled, false in other case
        @details Get
    */
    bool getNetGenerateDefaultRandom() const;

    /**
        @brief Get
        @return qreal with the
        @details Get
    */
    int getNetGenerateDefaultSeed() const;


    // SET FUNCTIONS

    /**
        @brief Set
        @param
        @details set
    */
    void setNetGenerateDefaultGrid(bool value);

    /**
        @brief Set
        @param
        @details set
    */
    void setNetGenerateDefaultGridNumber(int value);

    /**
        @brief Set
        @param
        @details set
    */
    void setNetGenerateDefaultGridLength(qreal value);

    /**
        @brief Set
        @param
        @details set
    */
    void setNetGenerateDefaultGridXNumber(int value);

    /**
        @brief Set
        @param
        @details set
    */
    void setNetGenerateDefaultGridYNumber(int value);

    /**
        @brief Set
        @param
        @details set
    */
    void setNetGenerateDefaultGridXLength(qreal value);

    /**
        @brief Set
        @param
        @details set
    */
    void setNetGenerateDefaultGridYLength(qreal value);

    /**
        @brief Set
        @param
        @details set
    */
    void setNetGenerateDefaultGridAttachLength(qreal value);

    /**
        @brief Set
        @param
        @details set
    */
    void setNetGenerateDefaultSpider(bool value);

    /**
        @brief Set
        @param
        @details set
    */
    void setNetGenerateDefaultSpiderArmNumber(int value);

    /**
        @brief Set
        @param
        @details set
    */
    void setNetGenerateDefaultSpiderCircleNumber(int value);

    /**
        @brief Set
        @param
        @details set
    */
    void setNetGenerateDefaultSpiderSpaceRadius(qreal value);

    /**
        @brief Set
        @param
        @details set
    */
    void setNetGenerateDefaultSpiderOmitCenter(bool value);

    /**
        @brief Set
        @param
        @details set
    */
    void setNetGenerateDefaultRand(bool value);

    /**
        @brief Set
        @param
        @details set
    */
    void setNetGenerateDefaultRandIterations(int value);

    /**
        @brief Set
        @param
        @details set
    */
    void setNetGenerateDefaultRandBidiProbability(qreal value);

    /**
        @brief Set
        @param
        @details set
    */
    void setNetGenerateDefaultRandMaxDistance(qreal value);

    /**
        @brief Set
        @param
        @details set
    */
    void setNetGenerateDefaultRandMinDistance(qreal value);

    /**
        @brief Set
        @param
        @details set
    */
    void setNetGenerateDefaultRandMinAngle(qreal value);

    /**
        @brief Set
        @param
        @details set
    */
    void setNetGenerateDefaultRandNumTries(int value);

    /**
        @brief Set
        @param
        @details set
    */
    void setNetGenerateDefaultRandConnectivity(qreal value);

    /**
        @brief Set
        @param
        @details set
    */
    void setNetGenerateDefaultRandNeighborDist1(qreal value);

    /**
        @brief Set
        @param
        @details set
    */
    void setNetGenerateDefaultRandNeighborDist2(qreal value);

    /**
        @brief Set
        @param
        @details set
    */
    void setNetGenerateDefaultRandNeighborDist3(qreal value);

    /**
        @brief Set
        @param
        @details set
    */
    void setNetGenerateDefaultRandNeighborDist4(qreal value);

    /**
        @brief Set
        @param
        @details set
    */
    void setNetGenerateDefaultRandNeighborDist5(qreal value);

    /**
        @brief Set
        @param
        @details set
    */
    void setNetGenerateDefaultRandNeighborDist6(qreal value);

    /**
        @brief Set
        @param
        @details set
    */
    void setNetGenerateDefaultOutputPrefix(const QString &value);

    /**
        @brief Set
        @param
        @details set
    */
    void setNetGenerateDefaultOutputFile(const QString &value);

    /**
        @brief Set
        @param
        @details set
    */
    void setNetGenerateDefaultPlainOutputPrefix(const QString &value);

    /**
        @brief Set
        @param
        @details set
    */
    void setNetGenerateDefaultJunctionsJoinOutput(const QString &value);

    /**
        @brief Set
        @param
        @details set
    */
    void setNetGenerateDefaultAmitranOutput(const QString &value);

    /**
        @brief Set
        @param
        @details set
    */
    void setNetGenerateDefaultMatsimOutput(const QString &value);

    /**
        @brief Set
        @param
        @details set
    */
    void setNetGenerateDefaultOpendriveOutput(const QString &value);

    /**
        @brief Set
        @param
        @details set
    */
    void setNetGenerateDefaultDlrNavteqOutput(const QString &value);

    /**
        @brief Set
        @param
        @details set
    */
    void setNetGenerateDefaultOutputStreetNames(bool value);

    /**
        @brief Set
        @param
        @details set
    */
    void setNetGenerateDefaultOutputOriginalNames(bool value);

    /**
        @brief Set
        @param
        @details set
    */
    void setNetGenerateDefaultStreetSignOutput(const QString &value);

    /**
        @brief Set
        @param
        @details set
    */
    void setNetGenerateDefaultTlsSet(const QString &value);

    /**
        @brief Set
        @param
        @details set
    */
    void setNetGenerateDefaultTlsUnset(const QString &value);

    /**
        @brief Set
        @param
        @details set
    */
    void setNetGenerateDefaultTlsGuess(bool value);

    /**
        @brief Set
        @param
        @details set
    */
    void setNetGenerateDefaultTlsGuessJoining(bool value);

    /**
        @brief Set
        @param
        @details set
    */
    void setNetGenerateDefaultTlsJoin(bool value);

    /**
        @brief Set
        @param
        @details set
    */
    void setNetGenerateDefaultTlsGreenTime(int value);

    /**
        @brief Set
        @param
        @details set
    */
    void setNetGenerateDefaultTlsYellowMinDecel(qreal value);

    /**
        @brief Set
        @param
        @details set
    */
    void setNetGenerateDefaultTlsYellowPatchSmall(bool value);

    /**
        @brief Set
        @param
        @details set
    */
    void setNetGenerateDefaultTlsYellowTime(int value);

    /**
        @brief Set
        @param
        @details set
    */
    void setNetGenerateDefaultTlsHalfOffset(const QString &value);

    /**
        @brief Set
        @param
        @details set
    */
    void setNetGenerateDefaultTlsQuarterOffset(const QString &value);

    /**
        @brief Set
        @param
        @details set
    */
    void setNetGenerateDefaultTlsDefaultType(const QString &value);

    /**
        @brief Set
        @param
        @details set
    */
    void setNetGenerateDefaultKeepEdgesMinSpeed(qreal value);

    /**
        @brief Set
        @param
        @details set
    */
    void setNetGenerateDefaultRemoveEdgesExplicit(const QString &value);

    /**
        @brief Set
        @param
        @details set
    */
    void setNetGenerateDefaultKeepEdgesExplicit(const QString &value);

    /**
        @brief Set
        @param
        @details set
    */
    void setNetGenerateDefaultKeepEdgesInputFile(const QString &value);

    /**
        @brief Set
        @param
        @details set
    */
    void setNetGenerateDefaultKeepEdgesInBoundary(const QString &value);

    /**
        @brief Set
        @param
        @details set
    */
    void setNetGenerateDefaultKeepEdgesInGeoBoundary(const QString &value);

    /**
        @brief Set
        @param
        @details set
    */
    void setNetGenerateDefaultKeepNodesUnregulated(bool value);

    /**
        @brief Set
        @param
        @details set
    */
    void setNetGenerateDefaultKeepNodesUnregulatedExplicit(const QString &value);

    /**
        @brief Set
        @param
        @details set
    */
    void setNetGenerateDefaultKeepNodesUnregulatedDistrictNodes(bool value);

    /**
        @brief Set
        @param
        @details set
    */
    void setNetGenerateDefaultNoInternalLinks(bool value);

    /**
        @brief Set
        @param
        @details set
    */
    void setNetGenerateDefaultNoTurnarounds(bool value);

    /**
        @brief Set
        @param
        @details set
    */
    void setNetGenerateDefaultNoTurnaroundsTls(bool value);

    /**
        @brief Set
        @param
        @details set
    */
    void setNetGenerateDefaultNoLeftConnections(bool value);

    /**
        @brief Set
        @param
        @details set
    */
    void setNetGenerateDefaultOffsetDisableNormalization(bool value);

    /**
        @brief Set
        @param
        @details set
    */
    void setNetGenerateDefaultOffsetX(qreal value);

    /**
        @brief Set
        @param
        @details set
    */
    void setNetGenerateDefaultOffsetY(qreal value);

    /**
        @brief Set
        @param
        @details set
    */
    void setNetGenerateDefaultFlipYAxis(bool value);

    /**
        @brief Set
        @param
        @details set
    */
    void setNetGenerateDefaultRoundaboutsGuess(bool value);

    /**
        @brief Set
        @param
        @details set
    */
    void setNetGenerateDefaultLefthand(bool value);

    /**
        @brief Set
        @param
        @details set
    */
    void setNetGenerateDefaultJunctionsJoin(bool value);

    /**
        @brief Set
        @param
        @details set
    */
    void setNetGenerateDefaultJunctionsJoinDist(qreal value);

    /**
        @brief Set
        @param
        @details set
    */
    void setNetGenerateDefaultJunctionsCornerDetail(int value);

    /**
        @brief Set
        @param
        @details set
    */
    void setNetGenerateDefaultCheckLaneFoesRoundabout(bool value);

    /**
        @brief Set
        @param
        @details set
    */
    void setNetGenerateDefaultCheckLaneFoesAll(bool value);

    /**
        @brief Set
        @param
        @details set
    */
    void setNetGenerateDefaultSidewalksGuess(bool value);

    /**
        @brief Set
        @param
        @details set
    */
    void setNetGenerateDefaultSidewalksGuessMaxSpeed(qreal value);

    /**
        @brief Set
        @param
        @details set
    */
    void setNetGenerateDefaultSidewalksGuessMinSpeed(qreal value);

    /**
        @brief Set
        @param
        @details set
    */
    void setNetGenerateDefaultSidewalksGuessFromPermissions(bool value);

    /**
        @brief Set
        @param
        @details set
    */
    void setNetGenerateDefaultCrossingsGuess(bool value);

    /**
        @brief Set
        @param
        @details set
    */
    void setNetGenerateDefaultTlsJoinDist(qreal value);

    /**
        @brief Set
        @param
        @details set
    */
    void setNetGenerateDefaultDefaultLanenumber(int value);

    /**
        @brief Set
        @param
        @details set
    */
    void setNetGenerateDefaultDefaultSpeed(qreal value);

    /**
        @brief Set
        @param
        @details set
    */
    void setNetGenerateDefaultDefaultPriority(int value);

    /**
        @brief Set
        @param
        @details set
    */
    void setNetGenerateDefaultDefaultSidewalkWidth(qreal value);

    /**
        @brief Set
        @param
        @details set
    */
    void setNetGenerateDefaultDefaultJunctionType(const QString &value);

    /**
        @brief Set
        @param
        @details set
    */
    void setNetGenerateDefaultVerbose(bool value);

    /**
        @brief Set
        @param
        @details set
    */
    void setNetGenerateDefaultPrintOptions(bool value);

    /**
        @brief Set
        @param
        @details set
    */
    void setNetGenerateDefaultHelp(bool value);

    /**
        @brief Set
        @param
        @details set
    */
    void setNetGenerateDefaultVersion(bool value);

    /**
        @brief Set
        @param
        @details set
    */
    void setNetGenerateDefaultXmlValidation(const QString &value);

    /**
        @brief Set
        @param
        @details set
    */
    void setNetGenerateDefaultXmlValidationNet(const QString &value);

    /**
        @brief Set
        @param
        @details set
    */
    void setNetGenerateDefaultNoWarnings(bool value);

    /**
        @brief Set
        @param
        @details set
    */
    void setNetGenerateDefaultLog(const QString &value);

    /**
        @brief Set
        @param
        @details set
    */
    void setNetGenerateDefaultMessageLog(const QString &value);

    /**
        @brief Set
        @param
        @details set
    */
    void setNetGenerateDefaultErrorLog(const QString &value);

    /**
        @brief Set
        @param
        @details set
    */
    void setNetGenerateDefaultRandom(bool value);

    /**
        @brief Set
        @param
        @details set
    */
    void setNetGenerateDefaultSeed(int value);


private:

    // Forces NETGEN to build a gridLike network; default: false
    bool netGenerateDefaultGrid;

    // The number of junctions in both dirs; default: 5
    int netGenerateDefaultGridNumber;

    // The length of streets in both dirs; default: 100
    qreal netGenerateDefaultGridLength;

    // The number of junctions in xDir; Overrides netGenerateDefaultGridNumber; default: 5
    int netGenerateDefaultGridXNumber;

    // The number of junctions in yDir; Overrides netGenerateDefaultGridNumber; default: 5
    int netGenerateDefaultGridYNumber;

    // The length of horizontal streets; Overrides netGenerateDefaultGridLength; default: 100
    qreal netGenerateDefaultGridXLength;

    // The length of vertical streets; Overrides netGenerateDefaultGridLength; default: 100
    qreal netGenerateDefaultGridYLength;

    // The length of streets attached at the boundary; 0 means no streets are attached; default: 0
    qreal netGenerateDefaultGridAttachLength;

    // Forces NETGEN to build a spiderNetLike network; default: false
    bool netGenerateDefaultSpider;

    // The number of axes within the net; default: 13
    int netGenerateDefaultSpiderArmNumber;

    // The number of circles of the net; default: 20
    int netGenerateDefaultSpiderCircleNumber;

    // The distances between the circles; default: 100
    qreal netGenerateDefaultSpiderSpaceRadius;

    // Omit the central node of the network; default: false
    bool netGenerateDefaultSpiderOmitCenter;

    // Forces NETGEN to build a random network; default: false
    bool netGenerateDefaultRand;

    // Describes how many times an edge shall be added to the net; default: 2000
    int netGenerateDefaultRandIterations;

    // Defines the probability to build a reverse edge; default: 1
    qreal netGenerateDefaultRandBidiProbability;

    // The maximum distance for each edge; default: 250
    qreal netGenerateDefaultRandMaxDistance;

    // The minimum distance for each edge; default: 100
    qreal netGenerateDefaultRandMinDistance;

    // The minimum angle for each pair of (bidirectional) roads; default: 0.785398
    qreal netGenerateDefaultRandMinAngle;

    // The number of tries for creating each node; default: 50
    int netGenerateDefaultRandNumTries;

    // Probability for roads to continue at each node; default: 0.95
    qreal netGenerateDefaultRandConnectivity;

    // Probability for a node having exactly 1 neighbor; default: 0
    qreal netGenerateDefaultRandNeighborDist1;

    // Probability for a node having exactly 2 neighbors; default: 0
    qreal netGenerateDefaultRandNeighborDist2;

    // Probability for a node having exactly 3 neighbors; default: 10
    qreal netGenerateDefaultRandNeighborDist3;

    // Probability for a node having exactly 4 neighbors; default: 10
    qreal netGenerateDefaultRandNeighborDist4;

    // Probability for a node having exactly 5 neighbors; default: 2
    qreal netGenerateDefaultRandNeighborDist5;

    // Probability for a node having exactly 6 neighbors; default: 1
    qreal netGenerateDefaultRandNeighborDist6;

    // Prefix which is applied to all output files. The special string 'TIME' is replaced by the current time.
    QString netGenerateDefaultOutputPrefix;

    // The generated net will be written to FILE
    QString netGenerateDefaultOutputFile;

    // Prefix of files to write plain xml nodes, edges and connections to
    QString netGenerateDefaultPlainOutputPrefix;

    // Writes information about joined junctions to FILE (can be loaded as additional nodeFile to reproduce joins
    QString netGenerateDefaultJunctionsJoinOutput;

    // The generated net will be written to FILE using Amitran format
    QString netGenerateDefaultAmitranOutput;

    // The generated net will be written to FILE using MATsim format
    QString netGenerateDefaultMatsimOutput;

    // The generated net will be written to FILE using OpenDRIVE format
    QString netGenerateDefaultOpendriveOutput;

    // The generated net will be written to dlrNavteq files with the given PREFIX
    QString netGenerateDefaultDlrNavteqOutput;

    // Street names will be included in the output (if available); default: false
    bool netGenerateDefaultOutputStreetNames;

    // Writes original names, if given, as parameter; default: false
    bool netGenerateDefaultOutputOriginalNames;

    // Writes street signs as POIs to FILE
    QString netGenerateDefaultStreetSignOutput;

    // Interprets STR as list of junctions to be controlled by TLS
    QString netGenerateDefaultTlsSet;

    // Interprets STR as list of junctions to be not controlled by TLS
    QString netGenerateDefaultTlsUnset;

    // Turns on TLS guessing; default: false
    bool netGenerateDefaultTlsGuess;

    // Includes node clusters into guess; default: false
    bool netGenerateDefaultTlsGuessJoining;

    // Tries to cluster tlsControlled nodes; default: false
    bool netGenerateDefaultTlsJoin;

    // Use INT as green phase duration; default: 31
    int netGenerateDefaultTlsGreenTime;

    // Defines smallest vehicle deceleration; default: 3
    qreal netGenerateDefaultTlsYellowMinDecel;

    // Given yellow times are patched even if being too short; default: false
    bool netGenerateDefaultTlsYellowPatchSmall;

    // Set INT as fixed time for yellow phase durations
    int netGenerateDefaultTlsYellowTime;

    // TLSs in STR will be shifted by halfPhase
    QString netGenerateDefaultTlsHalfOffset;

    // TLSs in STR will be shifted by quarterPhase
    QString netGenerateDefaultTlsQuarterOffset;

    // TLSs with unspecified type will use STR as their algorithm; default: static
    QString netGenerateDefaultTlsDefaultType;

    // Only keep edges with speed in meters/second > FLOAT
    qreal netGenerateDefaultKeepEdgesMinSpeed;

    // Remove edges in STR
    QString netGenerateDefaultRemoveEdgesExplicit;

    // Only keep edges in STR
    QString netGenerateDefaultKeepEdgesExplicit;

    // Only keep edges in FILE
    QString netGenerateDefaultKeepEdgesInputFile;

    // Only keep edges which are located within the given boundary (given either as CARTESIAN corner coordinates <xmin,ymin,xmax,ymax> or as polygon <x0,y0,x1,y1,...>)
    QString netGenerateDefaultKeepEdgesInBoundary;

    // Only keep edges which are located within the given boundary (given either as GEODETIC corner coordinates <lonMin,latMin,lonMax,latMax> or as polygon <lon0,lat0,lon1,lat1,...>)
    QString netGenerateDefaultKeepEdgesInGeoBoundary;

    // All nodes will be unregulated; default: false
    bool netGenerateDefaultKeepNodesUnregulated;

    // Do not regulate nodes in STR
    QString netGenerateDefaultKeepNodesUnregulatedExplicit;

    // Do not regulate district nodes; default: false
    bool netGenerateDefaultKeepNodesUnregulatedDistrictNodes;

    // Omits internal links; default: false
    bool netGenerateDefaultNoInternalLinks;

    // Disables building turnarounds; default: false
    bool netGenerateDefaultNoTurnarounds;

    // Disables building turnarounds at tlsControlled junctions; default: false
    bool netGenerateDefaultNoTurnaroundsTls;

    // Disables building connections to left; default: false
    bool netGenerateDefaultNoLeftConnections;

    // Turn off normalizing node positions; default: false
    bool netGenerateDefaultOffsetDisableNormalization;

    // Adds FLOAT to net xPositions; default: 0
    qreal netGenerateDefaultOffsetX;

    // Adds FLOAT to net yPositions; default: 0
    qreal netGenerateDefaultOffsetY;

    // Flips the yCoordinate along zero; default: false
    bool netGenerateDefaultFlipYAxis;

    // Enable roundaboutGuessing; default: false
    bool netGenerateDefaultRoundaboutsGuess;

    // Assumes leftHand traffic on the network; default: false
    bool netGenerateDefaultLefthand;

    // Joins junctions that are close to each other (recommended for OSM import); default: false
    bool netGenerateDefaultJunctionsJoin;

    // Determines the maximal distance for joining junctions (defaults to 10); default: 10
    qreal netGenerateDefaultJunctionsJoinDist;

    // Generate INT intermediate points to smooth out intersection corners; default: 0
    int netGenerateDefaultJunctionsCornerDetail;

    // Allow driving onto a multiLane road if there are foes on other lanes (at roundabouts); default: true
    bool netGenerateDefaultCheckLaneFoesRoundabout;

    // Allow driving onto a multiLane road if there are foes on other lanes (everywhere); default: false
    bool netGenerateDefaultCheckLaneFoesAll;

    // Guess pedestrian sidewalks based on edge speed; default: false
    bool netGenerateDefaultSidewalksGuess;

    // Add sidewalks for edges with a speed equal or below the given limit; default: 13.89
    qreal netGenerateDefaultSidewalksGuessMaxSpeed;

    // Add sidewalks for edges with a speed above the given limit; default: 5.8
    qreal netGenerateDefaultSidewalksGuessMinSpeed;

    // Add sidewalks for edges that allow pedestrians on any of their lanes regardless of speed; default: false
    bool netGenerateDefaultSidewalksGuessFromPermissions;

    // Guess pedestrian crossings based on the presence of sidewalks; default: false
    bool netGenerateDefaultCrossingsGuess;

    // Determines the maximal distance for joining traffic lights (defaults to 20); default: 20
    qreal netGenerateDefaultTlsJoinDist;

    // The default number of lanes in an edge; default: 1
    int netGenerateDefaultDefaultLanenumber;

    // The default speed on an edge (in m/s); default: 13.9
    qreal netGenerateDefaultDefaultSpeed;

    // The default priority of an edge; default: -1
    int netGenerateDefaultDefaultPriority;

    // The default width of added sidewalks; default: 2
    qreal netGenerateDefaultDefaultSidewalkWidth;

    // [trafficLight|priority|rightBeforeLeft] Determines the type of the build junctions
    QString netGenerateDefaultDefaultJunctionType;

    // Switches to verbose output; default: false
    bool netGenerateDefaultVerbose;

    // Prints option values before processing; default: false
    bool netGenerateDefaultPrintOptions;

    // Prints this screen; default: false
    bool netGenerateDefaultHelp;

    // Prints the current version; default: false
    bool netGenerateDefaultVersion;

    // Set schema validation scheme of XML inputs ("never", "auto" or "always"); default: auto
    QString netGenerateDefaultXmlValidation;

    // Set schema validation scheme of SUMO network inputs ("never", "auto" or "always"); default: never
    QString netGenerateDefaultXmlValidationNet;

    // Disables output of warnings; default: false
    bool netGenerateDefaultNoWarnings;

    // Writes all messages to FILE (implies verbose)
    QString netGenerateDefaultLog;

    // Writes all nonError messages to FILE (implies verbose)
    QString netGenerateDefaultMessageLog;

    // Writes all warnings and errors to FILE
    QString netGenerateDefaultErrorLog;

    // Initialises the random number generator with the current system time; default: false
    bool netGenerateDefaultRandom;

    // Initialises the random number generator with the given value; default: 23423
    int netGenerateDefaultSeed;
};

#endif // NETGENERATECONFIGURATION_H
