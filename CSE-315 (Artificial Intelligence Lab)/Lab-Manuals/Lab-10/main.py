import random

class Individual:
    def __init__(self):
        self.gene_length = 5
        self.genes = [random.randint(0, 1) for _ in range(self.gene_length)]
        self.fitness = 0

    def calc_fitness(self):
        self.fitness = sum(self.genes)


class Population:
    def __init__(self, size=10):
        self.pop_size = size
        self.individuals = [Individual() for _ in range(size)]
        self.fittest = 0

    def initialize_population(self):
        self.individuals = [Individual() for _ in range(self.pop_size)]

    def calculate_fitness(self):
        for individual in self.individuals:
            individual.calc_fitness()
        self.get_fittest()

    def get_fittest(self):
        fittest_individual = max(self.individuals, key=lambda ind: ind.fitness)
        self.fittest = fittest_individual.fitness
        return fittest_individual

    def get_second_fittest(self):
        sorted_individuals = sorted(self.individuals, key=lambda ind: ind.fitness, reverse=True)
        return sorted_individuals[1]

    def get_least_fittest_index(self):
        min_fit = min(self.individuals, key=lambda ind: ind.fitness)
        return self.individuals.index(min_fit)


class SimpleDemoGA:
    def __init__(self):
        self.population = Population()
        self.fittest = None
        self.second_fittest = None
        self.generation_count = 0

    def selection(self):
        self.fittest = self.population.get_fittest()
        self.second_fittest = self.population.get_second_fittest()

    def crossover(self):
        crossover_point = random.randint(0, self.fittest.gene_length - 1)
        for i in range(crossover_point):
            self.fittest.genes[i], self.second_fittest.genes[i] = (
                self.second_fittest.genes[i],
                self.fittest.genes[i],
            )

    def mutation(self):
        for individual in [self.fittest, self.second_fittest]:
            mutation_point = random.randint(0, individual.gene_length - 1)
            individual.genes[mutation_point] = 1 - individual.genes[mutation_point]

    def get_fittest_offspring(self):
        return self.fittest if self.fittest.fitness > self.second_fittest.fitness else self.second_fittest

    def add_fittest_offspring(self):
        self.fittest.calc_fitness()
        self.second_fittest.calc_fitness()
        least_fit_index = self.population.get_least_fittest_index()
        self.population.individuals[least_fit_index] = self.get_fittest_offspring()

    def run(self):
        self.population.initialize_population()
        self.population.calculate_fitness()
        print(f"Generation: {self.generation_count} Fittest: {self.population.fittest}")

        while self.population.fittest < 5:
            self.generation_count += 1
            self.selection()
            self.crossover()
            if random.randint(0, 6) < 5:
                self.mutation()
            self.add_fittest_offspring()
            self.population.calculate_fitness()
            print(f"Generation: {self.generation_count} Fittest: {self.population.fittest}")

        print(f"\nSolution found in generation {self.generation_count}")
        best = self.population.get_fittest()
        print(f"Fitness: {best.fitness}")
        print("Genes:", ''.join(map(str, best.genes)))


if __name__ == "__main__":
    ga = SimpleDemoGA()
    ga.run()
