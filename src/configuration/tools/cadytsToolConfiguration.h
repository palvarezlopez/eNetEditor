#ifndef CADYTSTOOLCONFIGURATION_H
#define CADYTSTOOLCONFIGURATION_H

#include "eNetEditorToolConfiguration.h"


/*!
    \brief Cadyts configuration
    \author Pablo Álvarez López
    \date 2015
    \details Class to keep all parameters of cadyts tool, including configuration and default
    values of input, output and configuration parameters
 */
class cadytsToolConfiguration : public eNetEditorToolConfiguration
{
public:

    cadytsToolConfiguration();

    ~cadytsToolConfiguration();

    /**
        @brief Get
        @return QString with the
        @details Get
    */
    const QString &getCadytsDefaultRouteFile() const;

    /**
        @brief Get
        @return QString with the
        @details Get
    */
    const QString &getCadytsDefaultFlowsFile() const;

    /**
        @brief Get
        @return QString with the
        @details Get
    */
    const QString &getCadytsDefaultClasspath() const;

    /**
        @brief Get
        @return int with the
        @details Get
    */
    int getCadytsDefaultSteps() const;

    /**
        @brief Get
        @return int with the
        @details Get
    */
    int getCadytsDefaultScaled() const;

    /**
        @brief Get
        @return int with the
        @details Get
    */
    int getCadytsDefaultNumberOfIterations() const;

    /**
        @brief Get
        @return qreal with
        @details Get
    */
    qreal getCadytsDefaultVariance() const;

    /**
        @brief Get
        @return int with the
        @details Get
    */
    int getCadytsDefaultPreparatoryIterations() const;

    /**
        @brief Get
        @return QString with the
        @details Get
    */
    const QString &getCadytsDefaultFlowEvaluationFiles() const;

    /**
        @brief Get
        @return true if X is enabled, false in other case
        @details Get
    */
    bool getCadytsDefaultFitTrafficCounts() const;

    /**
        @brief Get
        @return qreal with
        @details Get
    */
    qreal getCadytsDefaultDeviation() const;

    /**
        @brief Get
        @return true if X is enabled, false in other case
        @details Get
    */
    bool getCadytsDefaultOverrideDepartTimes() const;

    /**
        @brief Get
        @return QString with the
        @details Get
    */
    const QString &getCadytsDefaulPrefixODMatrixFilesVisum() const;

    /**
        @brief Get
        @return QString with the
        @details Get
    */
    const QString &getCadytsDefaultPostfitAtacched() const;

    /**
        @brief Get
        @return true if X is enabled, false in other case
        @details Get
    */
    bool getCadytsDefaultWritteSummary() const;

    /**
        @brief Get
        @return true if X is enabled, false in other case
        @details Get
    */
    bool getCadytsDefaultWritteTripinfos() const;


    // SET FUNCTIONS


    /**
        @brief Set
        @param
        @details set
    */
    void setCadytsDefaultRouteFile(const QString &value);

    /**
        @brief Set
        @param
        @details set
    */
    void setCadytsDefaultFlowsFile(const QString &value);

    /**
        @brief Set
        @param
        @details set
    */
    void setCadytsDefaultClasspath(const QString &value);

    /**
        @brief Set
        @param
        @details set
    */
    void setCadytsDefaultSteps(int value);

    /**
        @brief Set
        @param
        @details set
    */
    void setCadytsDefaultScaled(int value);

    /**
        @brief Set
        @param
        @details set
    */
    void setCadytsDefaultNumberOfIterations(int value);

    /**
        @brief Set
        @param
        @details set
    */
    void setCadytsDefaultVariance(qreal value);

    /**
        @brief Set
        @param
        @details set
    */
    void setCadytsDefaultPreparatoryIterations(int value);

    /**
        @brief Set
        @param
        @details set
    */
    void setCadytsDefaultFlowEvaluationFiles(const QString &value);

    /**
        @brief Set
        @param
        @details set
    */
    void setCadytsDefaultFitTrafficCounts(bool value);

    /**
        @brief Set
        @param
        @details set
    */
    void setCadytsDefaultDeviation(qreal value);

    /**
        @brief Set
        @param
        @details set
    */
    void setCadytsDefaultOverrideDepartTimes(bool value);

    /**
        @brief Set
        @param
        @details set
    */
    void setCadytsDefaulPrefixODMatrixFilesVisum(const QString &value);

    /**
        @brief Set
        @param
        @details set
    */
    void setCadytsDefaultPostfitAtacched(const QString &value);

    /**
        @brief Set
        @param
        @details set
    */
    void setCadytsDefaultWritteSummary(bool value);

    /**
        @brief Set
        @param
        @details set
    */
    void setCadytsDefaultWritteTripinfos(bool value);


private:

    // route alternatives file from sumo (comma separated list) (in Cadyts: -choicesetfile)
    QString cadytsDefaultRouteFile;

    //-d adapt to the traffic flows on the edges defined in a given file (in Cadyts: -measfile)
    QString cadytsDefaultFlowsFile;

    //-c classpath for the calibrator, default= os.path.join(os.path.dirname(sys.argv[0]), "..", "contributed","calibration","cadytsSumoController.jar")
    QString cadytsDefaultClasspath;

    //-s last step of the calibration, default=100
    int cadytsDefaultSteps;

    //-S scaled demand, optional, default=2 (in Cadyts: -demandscale); If -M is defined, this parameter will be used in the calibration.
    int cadytsDefaultScaled;

    //-F define the number of iterations for stablizing the results in the DTA-calibration, default= 85 (in Cadyts: - freezeit)
    int cadytsDefaultNumberOfIterations;

    //-V define variance of the measured traffic flows for the DTA-calibration, default=1, (in Cadyts: varscale)
    qreal cadytsDefaultVariance;

    //-P number of preparatory iterations, default = 5 (in Cadyts: PREPITS)
    int cadytsDefaultPreparatoryIterations;

    //-W prefix of flow evaluation files; only for the calibration with use of detector data, optional (in Cadyts: -flowfile)
    QString cadytsDefaultFlowEvaluationFiles;

    //-Y fit the traffic counts as accurate as possible, default = False, (in Cadyts: -bruteforce)
    bool cadytsDefaultFitTrafficCounts;

    //-Z minimal traffic count standard deviation"), default = 25 (in Cadyts: -mincountstddev)
    qreal cadytsDefaultDeviation;

    //-O override depart times according to updated link travel times, default= False (in Cadyts: -overridett)
    bool cadytsDefaultOverrideDepartTimes;

    //-M prefix of OD matrix files in VISUM format (in Cadyts: - fmaprefix)
    QString cadytsDefaulPrefixODMatrixFilesVisum;

    //-N postfix attached to clone ids, default='-CLONE' (in Cadyts: -clonepostfix)
    QString cadytsDefaultPostfitAtacched;

    //-E No summary information is written by the simulation, default=False
    bool cadytsDefaultWritteSummary;

    //-T No tripinfos are written by the simulation, default=False
    bool cadytsDefaultWritteTripinfos;
};

#endif // CADYTSCONFIGURATION_H
