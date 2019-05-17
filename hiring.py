#!/bin/env python
# coding=UTF-8

################################################################################
# Get Cost
################################################################################

def cost(candidates):

    return sum(i[1] for i in candidates)


################################################################################
# Get Skills
################################################################################

def skills(candidates):

    return list({j for i in candidates for j in i[0]})


################################################################################
# Get Uncovered
################################################################################

def uncovered(project, skills):

    return list(set(project) - set(skills))


################################################################################
# Get Best Individual Candidate
################################################################################

def best_individual_candidate(project, candidates):

    return max(list(range(len(candidates))), key = lambda idx:
        len(set(project) & set(candidates[idx][0])) / candidates[idx][1])


################################################################################
# Get Team Of Best Individuals
################################################################################

def team_of_best_individuals(project, candidates):

    bestIndividualsList = []

    # Copy
    candidates = list(candidates)

    while project:
        bestIdx = best_individual_candidate(project, candidates)
        project = uncovered(project, candidates[bestIdx][0])
        bestIndividualsList.append(candidates.pop(bestIdx))

    return bestIndividualsList


################################################################################
# Permutations (From Python itertools.permutations)
################################################################################

def __permutations(candidates):

    listLen   = len(candidates)
    idxList   = list(range(listLen))
    cycleList = list(range(listLen, 0, -1))

    yield [i for i in candidates]

    while True:

        for i in reversed(range(listLen)):

            cycleList[i] -= 1

            if cycleList[i] == 0:
                idxList[i:]  = idxList[i + 1:] + [idxList[i]]
                cycleList[i] = listLen - i
            else:
                idxList[i], idxList[-cycleList[i]] = idxList[-cycleList[i]], idxList[i]
                yield [candidates[idx] for idx in idxList]
                break

        else:
            break


################################################################################
# Get Best Team
################################################################################

def best_team(project, candidates):

    minCost = float('inf')
    minList = None

    for candidatesList in __permutations(candidates):

        nowCost = 0
        uncoveredProjectList = project

        for idx, (skills, cost) in enumerate(candidatesList):

            uncoveredProjectList = uncovered(uncoveredProjectList, skills)
            nowCost += cost

            if not uncoveredProjectList and nowCost < minCost:
                minCost = nowCost
                minList = candidatesList[:idx + 1]

    return minList


################################################################################
# Main Program Define
################################################################################

def main():

    jess       = (["php", "java"], 200.)
    clark      = (["php", "c++", "go"], 1000.)
    john       = (["lua"], 500.)
    cindy      = (["php", "go", "word"], 240.)

    candidates = [jess, clark, john, cindy]
    project    = ["php", "java", "c++", "lua", "go"]

    print(cost([john, cindy]))
    print(skills([clark, cindy]))
    print(uncovered(project, skills([clark])))
    print(best_individual_candidate(project, candidates))
    print(team_of_best_individuals(project, candidates))
    print(best_team(project, candidates))


if __name__ == '__main__':
    main()